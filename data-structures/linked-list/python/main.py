"""
>>> linked_list = LinkedList()
>>> linked_list
LinkedList()
>>> linked_list.append(20)
>>> linked_list
LinkedList(20)
>>> linked_list.append(30)
>>> linked_list
LinkedList(20, 30)
>>> linked_list.insert(10)
>>> linked_list
LinkedList(10, 20, 30)
>>> for data in linked_list:
...    print(data)
10
20
30
>>> linked_list.size
3
>>> linked_list.remove(40)
>>> linked_list
LinkedList(10, 20, 30)
>>> linked_list.remove(20)
>>> linked_list
LinkedList(10, 30)
>>> linked_list.remove(30)
>>> linked_list
LinkedList(10)
>>> linked_list.remove(10)
>>> linked_list
LinkedList()
>>> linked_list.size
0
"""
from dataclasses import dataclass
from typing import Any, Iterable, Optional


@dataclass
class Node:
    data: Any
    next_node: Optional['Node'] = None


class LinkedList:
    def __init__(self) -> None:
        self._size = 0
        self._root = None

    def append(self, data: Any) -> None:
        """
        Insert a node on the end of the list, O(n)
        """
        self._size += 1
        node = Node(data=data)

        if self._root is None:
            self._root = node
            return

        actual = self._root
        while actual.next_node is not None:
            actual = actual.next_node

        actual.next_node = node

    def insert(self, data: Any) -> None:
        """
        Insert a node on the begin of the list: O(1)
        """
        self._size += 1
        if self._root is None:
            self._root = Node(data=data)
        else:
            node = Node(data=data, next_node=self._root)
            self._root = node

    def remove(self, data: Any) -> None:
        if self._root is None:
            return

        if self._root.data == data:
            self._root = self._root.next_node
            self._size -= 1
            return

        previous = self._root
        actual = self._root.next_node
        while actual.data != data:
            previous = actual
            actual = actual.next_node
            if actual is None:
                return

        previous.next_node = actual.next_node
        self._size -= 1

    @property
    def size(self) -> int:
        return self._size

    def __iter__(self) -> Iterable[Any]:
        if self._root is None:
            return

        yield self._root.data

        actual = self._root
        while actual.next_node is not None:
            actual = actual.next_node
            yield actual.data

    def __repr__(self) -> str:
        return f'LinkedList({", ".join(str(x) for x in self)})'


if __name__ == '__main__':
    import doctest
    doctest.testmod()
