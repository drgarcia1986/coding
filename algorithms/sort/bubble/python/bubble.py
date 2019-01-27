"""
>>> a = [1, 2, 3, 4, 5]
>>> bubble_sort(a)
>>> a
[1, 2, 3, 4, 5]
>>> a = [4, 2, 5, 1, 3]
>>> bubble_sort(a)
>>> a
[1, 2, 3, 4, 5]
"""


def bubble_sort(a):
    stop = False
    length = len(a)
    while not stop:
        stop = True
        for i in range(length-1):
            if a[i] > a[i+1]:
                a[i], a[i+1] = a[i+1], a[i]
                stop = False
        length -= 1


if __name__ == "__main__":
    import doctest
    doctest.testmod()
