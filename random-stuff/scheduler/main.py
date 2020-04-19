import asyncio
from random import randint


class Job:
    def __init__(self, task, scheduler, loop=None):
        self._scheduler = scheduler
        self._loop = loop or asyncio.get_event_loop()
        self._task = loop.create_task(task)
        self._task.add_done_callback(self._on_done)

    def _on_done(self, future):
        self._scheduler.set_done(self)

    async def wait(self):
        return await self._task


class Scheduler:
    def __init__(self, loop=None):
        self._loop = loop or asyncio.get_event_loop()
        self._pending = set()

    def add(self, task):
        job = Job(task, self, self._loop)
        self._pending.add(job)
        return job

    def set_done(self, job):
        self._pending.remove(job)

    async def join(self):
        for job in list(self._pending):
            await job.wait()


async def print_and_sleep(msg, interval, times):
    print(f'Starting {msg} with interval {interval} x{times}')
    for _ in range(times):
        print(msg)
        await asyncio.sleep(interval)
    print(f'Done: {msg}')


if __name__ == '__main__':
    scheduler = Scheduler()
    jobs = [
        scheduler.add(
            print_and_sleep(f'Job {i}', randint(1, 5), 5)
        )
        for i in range(1, 5)
    ]

    loop = asyncio.get_event_loop()
    loop.run_until_complete(scheduler.join())
    print('done')
