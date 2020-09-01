from __future__ import annotations
import abc
import asyncio
import sys
from functools import wraps
from typing import Set


class Observer(abc.ABC):
    @abc.abstractmethod
    async def update(self, subject: Subject) -> None:
        pass


class Subject(abc.ABC):
    @abc.abstractmethod
    def attach(self, observer: Observer) -> None:
        pass

    @abc.abstractmethod
    def detach(self, observer: Observer) -> None:
        pass

    @abc.abstractmethod
    async def notify(self) -> None:
        pass


class SimpleSubject(Subject):
    def __init__(self) -> None:
        self.observers: Set[Observer] = set()

    def attach(self, observer: Observer) -> None:
        self.observers.add(observer)

    def detach(self, observer: Observer) -> None:
        self.observers.remove(observer)

    async def notify(self) -> None:
        await asyncio.gather(*[o.update(self) for o in self.observers])

    def on_begin(self, func) -> None:
        @wraps(func)
        async def wrapper(*args, **kwargs):
            await self.notify()
            return await func(*args, **kwargs)
        return wrapper

    def on_completed(self, func) -> None:
        @wraps(func)
        async def wrapper(*args, **kwargs):
            result = await func(*args, **kwargs)
            await self.notify()
            return result
        return wrapper


class ToySubject(SimpleSubject):
    def __init__(self) -> None:
        super().__init__()
        self.state: str = ''

    async def update_state(self, value: str) -> None:
        self.state = value
        await self.notify()

    def __str__(self) -> str:
        return f'Current State -> {self.state}'


class PrinterObserver(Observer):
    async def update(self, subject: Subject) -> None:
        print(f'Receive a event of {subject.__class__.__name__}: {subject}')


class ExiterObserver(Observer):
    async def update(self, subject: Subject) -> None:
        if (
            isinstance(subject, ToySubject) and
            subject.state == 'exit'
        ):
            print('Im the exiter and now its time to exit')
            sys.exit(0)


toy = ToySubject()


@toy.on_begin
@toy.on_completed
async def say(text: str) -> None:
    print(f'Saying: {text}')


if __name__ == '__main__':
    loop = asyncio.get_event_loop()

    printer = PrinterObserver()
    exiter = ExiterObserver()

    toy.attach(printer)
    loop.run_until_complete(toy.update_state('hello'))

    toy.attach(exiter)
    loop.run_until_complete(toy.update_state('how are you?'))

    loop.run_until_complete(say('something'))

    toy.detach(printer)
    loop.run_until_complete(toy.update_state('exit'))
