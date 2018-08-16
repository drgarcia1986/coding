"""
>>> reverse_int(15)
51
>>> reverse_int(981)
189
>>> reverse_int(500)
5
>>> reverse_int(-15)
-51
>>> reverse_int(-90)
-9
"""


def reverse_int(n):
    """
    - Converting to string:
    is_negative = n < 0
    n = str(n)[::-1]
    if is_negative:
        n = n.replace('-', '')
        n = '-' + n
    return int(n)
    --------------
    Whitout convert to string:
    """
    is_negative = n < 0
    if is_negative:
        n *= -1
    res = 0
    while n != 0:
        res = res * 10 + n % 10
        n = n / 10
    return res if not is_negative else -res


if __name__ == "__main__":
    import doctest
    doctest.testmod()
