import asyncio

from main import dumps, loads, Command, Response


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

    async def set(self, key: str, value: str, ex: int = None) -> bool:
        if ex:
            await self._send_data(dumps('SET', key, value, 'EX', str(ex)))
        else:
            await self._send_data(dumps('SET', key, value))
        data = await self._read_data()
        return True if not data.error_code else False

    async def get(self, key: str) -> str:
        await self._send_data(dumps('GET', key))
        data = await self._read_data()
        return data.text if not data.error_code else data.error_code

    async def _send_data(self, cmd: Command):
        for c in cmd.chunks():
            self._writer.write(c)

        await self._writer.drain()

    async def _read_data(self) -> Response:
        empty = b''
        data = b''
        read_size = 100
        timeout = 1
        while True:
            try:
                chunk = await asyncio.wait_for(self._reader.read(read_size), timeout)
            except asyncio.TimeoutError:
                break
            if chunk == empty:
                break
            data += chunk

        return loads(data.decode())


async def new_redis(address: str = '127.0.0.1', port: int = 6379) -> Redis:
    redis = Redis(address, port)
    await redis.connect()
    return redis
