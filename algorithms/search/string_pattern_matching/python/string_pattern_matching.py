"""
>>> matching('aababba', 'abba')
3
>>> matching('cormen', 'skiena')
-1
"""

def matching(t: str, p: str) -> int:
    t_len = len(t)
    p_len = len(p)

    for i in range((t_len - p_len) + 1):
        j = 0
        while j < p_len and t[i+j] == p[j]:
            j += 1
        if j == p_len:
            return i
    return -1


if __name__ == '__main__':
    import doctest
    doctest.testmod()
