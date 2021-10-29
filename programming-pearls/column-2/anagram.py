"""
>>> find_anagrams(['pans', 'pots', 'opt', 'snap', 'stop', 'tops'])
(['pans', 'snap'], ['pots', 'stop', 'tops'], ['opt'])
"""
from collections import defaultdict
from typing import Generator, List, Tuple


def sign(word: str) -> str:
    return ''.join(sorted(word))


def group(words: Generator[Tuple[str, str], None, None]) -> Tuple[List[str]]:
    result = defaultdict(list)
    for s, w in words:
        result[s].append(w)
    return tuple(result.values())


def find_anagrams(words: List[str]) -> Tuple[List[str]]:
    return group(
        ((sign(w), w) for w in words)
    )


if __name__ == '__main__':
    import doctest
    doctest.testmod()
