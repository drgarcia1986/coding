"""
>>> a = [1, 2, 3, 4, 5]
>>> insertion_sort(a)
>>> a
[1, 2, 3, 4, 5]
>>> a = [4, 2, 5, 1, 3]
>>> insertion_sort(a)
>>> a
[1, 2, 3, 4, 5]
"""


def insertion_sort(a):
    for i in range(1, len(a)):
        actual = a[i]
        j = i
        while j > 0 and actual < a[j-1]:
            a[j] = a[j-1]
            j -= 1
        a[j] = actual


if __name__ == "__main__":
    import doctest
    doctest.testmod()
