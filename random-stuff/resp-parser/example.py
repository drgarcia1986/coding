import asyncio
import time

from cli import Redis


async def run():
    async with Redis() as cli:
        key = "KEY"
        value = "VALUE"
        ex = 5
        print(f'Set [{key}]:[{value}] with EX [{ex}]')
        set_result = await cli.set(key, value, ex)
        print(f'Set result: {set_result}')
        get_result = await cli.get(key)
        print(f'Get result: {get_result}')
        print(f'Sleeping [{ex}] seconds')
        time.sleep(ex)
        get_result = await cli.get(key)
        print(f'Get result: {get_result}')


if __name__ == '__main__':
    asyncio.run(run())
