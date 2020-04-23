"""
>>> loads('+OK\\r\\n')
Response(text='OK', error_code=None)
>>> loads(':1000\\r\\n')
Response(text=1000, error_code=None)
>>> loads('-ERR unknown command "foobar"\\r\\n')
Response(text='unknown command "foobar"', error_code='ERR')
>>> loads('$6\\r\\nfoobar\\r\\n')
Response(text='foobar', error_code=None)
>>> loads('&UNKNOW')
Traceback (most recent call last):
    ...
InvalidResponse: Invalid response: &UNKNOW
>>> dumps('SET', 'my_key', 'my_value')
Command("SET my_key my_value")
>>> list(dumps('SET', 'my_key', 'my_value').chunks())
['*3\\r\\n', '$3\\r\\n', 'SET\\r\\n', '$6\\r\\n', 'my_key\\r\\n', '$8\\r\\n', 'my_value\\r\\n']
>>> list(dumps('SET', 'my_key', 'my_value'))
['*3\\r\\n', '$3\\r\\n', 'SET\\r\\n', '$6\\r\\n', 'my_key\\r\\n', '$8\\r\\n', 'my_value\\r\\n']
"""
from dataclasses import dataclass
from typing import Iterable, Optional, List, Union, Tuple


class InvalidResponse(Exception):
    def __init__(self, msg: str) -> None:
        self.msg = msg

    def __str__(self) -> str:
        return f'Invalid response: {self.msg}'


@dataclass
class Response:
    text: Union[str, int]
    error_code: Optional[str] = None


class Command:
    def __init__(self, *args: Tuple[str]) -> None:
        self._args = args

    def chunks(self) -> Iterable[str]:
        yield f'*{len(self._args)}\r\n'

        for arg in self._args:
            yield f'${len(arg)}\r\n'
            yield f'{arg}\r\n'

    def __iter__(self) -> Iterable[str]:
        return self.chunks()

    def __repr__(self) -> str:
        return f'Command("{" ".join(self._args)}")'


def _parse_error(msg: str) -> Response:
    error_code, *msg_ = msg.split()
    return Response(text=' '.join(msg_).strip(), error_code=error_code)


def _parse_bulk_string(msg: str) -> Response:
    _, *msg_ = msg.split()
    return Response(text=' '.join(msg_).strip())


_PARSERS = {
    '+': lambda msg: Response(text=msg.strip()),
    ':': lambda msg: Response(text=int(msg.strip())),
    '-': _parse_error,
    '$': _parse_bulk_string,
}

def loads(msg: str) -> Response:
    msg_type = msg[0]
    parser = _PARSERS.get(msg_type)
    if not parser:
        raise InvalidResponse(msg)
    return parser(msg[1:])

def dumps(command: str, *args: List[str]) -> Command:
    return Command(command, *args)


if __name__ == "__main__":
    import doctest
    doctest.testmod()
