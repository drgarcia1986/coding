"""
>>> arr = [1, 2, 3, 4, 5]
>>> binary_search(arr, 2)
True
>>> arr = [1, 2, 3, 4]
>>> binary_search(arr, 3)
True
>>> arr = [1, 2, 3, 4]
>>> binary_search(arr, 1)
True
>>> arr = [1, 2, 3, 4]
>>> binary_search(arr, 4)
True
>>> arr = [2, 4, 6, 8, 10]
>>> binary_search(arr, 3)
False
>>> arr = [2, 4, 6, 8, 10, 12]
>>> binary_search(arr, 3)
False
"""


def binary_search(arr, x):
    if len(arr) == 0:
        return False
    base = len(arr) / 2
    if arr[base] == x:
        return True
    if arr[base] > x:
        return binary_search(arr[:base], x)
    return binary_search(arr[base+1:], x)


if __name__ == "__main__":
    import doctest
    doctest.testmod()
