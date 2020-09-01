import asyncio
import json
import zlib

import aiohttp


async def post(url, data):
    headers = {'Content-Encoding': 'gzip'}
    async with aiohttp.ClientSession() as session:
        async with session.post(url, data=data, headers=headers) as response:
            return response.headers, response.status, (await response.json())


if __name__ == '__main__':
    data = zlib.compress(json.dumps({'my': 'payload'}).encode())
    headers, status, content = asyncio.run(post('http://localhost', data=data))

    print(headers)
    print(status)
    print(content)
