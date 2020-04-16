import asyncio
from typing import List


class Redis:
    def __init__(self, address: str, port: int):
        self.address = address
        self.port = port
        self._reader = None
        self._writer = None

    async def connect(self) -> None:
        self._reader, self._writer = await asyncio.open_connection(
            self.address, self.port
        )

    async def close(self) -> None:
        self._writer.close()
        await self._writer.wait_closed()

    async def set(self, key: str, value: str) -> bool:
        await self._send_data('SET', key, value)

        data = await self._read_data()
        return 'Success' if self._process_data(data) == 'OK' else data

    async def get(self, key: str) -> str:
        await self._send_data('GET', key)
        data = await self._read_data()
        return self._process_data(data)

    def _process_data(self, data: str) -> str:
        if not data:
            return ''

        if data.startswith('+'):
            return data[1:]

        _, *data = data.split('\r\n')
        return data[0] if data else ''

    async def _send_data(self, *args: List[str]):
        self._writer.write(f'*{len(args)}\r\n'.encode())

        for arg in args:
            self._writer.write(f'${len(arg)}\r\n'.encode())
            self._writer.write(f'{arg}\r\n'.encode())

        await self._writer.drain()

    async def _read_data(self) -> str:
        data = b''
        while True:
            try:
                chunk = await asyncio.wait_for(self._reader.read(100), 0.1)
            except asyncio.exceptions.TimeoutError:
                break
            if chunk == b'':
                break
            data += chunk

        return data.decode().strip()


async def new_redis(address: str='127.0.0.1', port: int=6379) -> Redis:
    redis = Redis(address, port)
    await redis.connect()
    return redis


async def run() -> None:
    print('===> Redis client <===')
    print('# Ctrl+c to close the client')

    redis = await new_redis()
    print('* CONNECTED *')

    while True:
        try:
            msg = input('> ')
        except KeyboardInterrupt:
            await redis.close()
            print('Bye!')
            return

        command, key, *args = msg.split()
        if command == 'get':
            print(await redis.get(key))
        elif command == 'set':
            print(await redis.set(key, ' '.join(args)))


if __name__ == '__main__':
    asyncio.run(run())
