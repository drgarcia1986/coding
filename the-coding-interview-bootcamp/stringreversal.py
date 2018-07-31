"""
>>> reverse('apple')
'elppa'
>>> reverse('hello')
'olleh'
>>> reverse('Greetings!')
'!sgniteerG'
>>> reverse('  abcd')
'dcba  '
"""


def reverse(s):
    """
    - Pythonic way
    return s[::-1]
    or
    return ''.join(reversed(s))
    --------------
    - O(n)
    rev = ''
    for c in s:
        rev = c + rev
    return rev
    --------------
    - O(n) one line
    return reduce(lambda r, c: c + r, s)
    --------------
    - O(n/2)
    """
    value = list(s)
    len_v = len(value)
    for i in range(len_v / 2):
        value[i], value[len_v-i-1] = value[len_v-i-1], value[i]
    return ''.join(value)


if __name__ == "__main__":
    import doctest
    doctest.testmod()
