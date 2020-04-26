"""
>>> double_linked_list = DoubleLinkedList()
>>> double_linked_list
DoubleLinkedList()
>>> double_linked_list.append(20)
>>> double_linked_list
DoubleLinkedList(20)
>>> double_linked_list.append(30)
>>> double_linked_list
DoubleLinkedList(20, 30)
>>> double_linked_list.insert(10)
>>> double_linked_list
DoubleLinkedList(10, 20, 30)
>>> for data in double_linked_list:
...    print(data)
10
20
30
>>> for data in double_linked_list.reverse():
...    print(data)
30
20
10
>>> double_linked_list.size
3
>>> double_linked_list.remove(40)
>>> double_linked_list
DoubleLinkedList(10, 20, 30)
>>> double_linked_list.remove(20)
>>> double_linked_list
DoubleLinkedList(10, 30)
>>> double_linked_list.remove(30)
>>> double_linked_list
DoubleLinkedList(10)
>>> double_linked_list.remove(10)
>>> double_linked_list
DoubleLinkedList()
>>> double_linked_list.size
0
"""
from dataclasses import dataclass
from typing import Any, Iterable, Optional


@dataclass
class Node:
    data: Any
    next_node: Optional['Node'] = None
    previous_node: Optional['Node'] = None


class DoubleLinkedList:
    def __init__(self) -> None:
        self._size = 0
        self._root = None
        self._last = None

    def append(self, data: Any) -> None:
        """
        Insert a node on the end of the list, O(n)
        """
        self._size += 1
        node = Node(data=data)

        if self._root is None:
            self._root = node
            return

        if self._last is None:
            node.previous_node = self._root
            self._root.next_node = node
        else:
            node.previous_node = self._last
            self._last.next_node = node

        self._last = node

    def insert(self, data: Any) -> None:
        """
        Insert a node on the begin of the list: O(1)
        """
        self._size += 1
        if self._root is None:
            self._root = Node(data=data)
        else:
            node = Node(data=data, next_node=self._root)
            self._root.previous_node = node
            self._root = node

    def remove(self, data: Any) -> None:
        if self._root is None:
            return

        if self._root.data == data:
            self._root = self._root.next_node
            if self._root is not None:
                self._root.previous_node = None
            self._size -= 1
            return

        if self._last is not None and self._last.data == data:
            self._last = self._last.previous_node
            self._last.next_node = None
            self._size -= 1
            return

        previous = self._root
        actual = self._root.next_node
        while actual is not None and actual.data != data:
            previous = actual
            actual = actual.next_node

        if actual is None:
            return

        previous.next_node = actual.next_node
        actual.next_node.previous_node = previous

        self._size -= 1

    @property
    def size(self) -> int:
        return self._size

    def reverse(self) -> Iterable[Any]:
        if self._root is None:
            return
        if self._last is None:
            yield self._root.data
            return

        actual = self._last
        while actual is not None:
            yield actual.data
            actual = actual.previous_node

    def __iter__(self) -> Iterable[Any]:
        if self._root is None:
            return

        yield self._root.data

        actual = self._root
        while actual.next_node is not None:
            actual = actual.next_node
            yield actual.data

    def __repr__(self) -> str:
        return f'DoubleLinkedList({", ".join(str(x) for x in self)})'


if __name__ == '__main__':
    import doctest
    doctest.testmod()
