"""
>>> a = [1, 2, 3, 4, 5]
>>> selection_sort(a)
>>> a
[1, 2, 3, 4, 5]
>>> a = [4, 2, 5, 1, 3]
>>> selection_sort(a)
>>> a
[1, 2, 3, 4, 5]
"""


def selection_sort(a):
    length = len(a)
    for i in range(length):
        min_idx = i
        for j in range(i+1, length):
            if a[j] < a[min_idx]:
                min_idx = j
        if min_idx != i:
            a[i], a[min_idx] = a[min_idx], a[i]


if __name__ == "__main__":
    import doctest
    doctest.testmod()
