"""
>>> palindrome('abba')
True
>>> palindrome('box')
False
>>> palindrome('racecar')
True
>>> palindrome('madam')
True
>>> palindrome('false')
False
>>> palindrome('Fish hsif')
False
"""


def palindrome(s):
    a = list(s)
    len_a = len(a)
    for i in range(len_a / 2):
        if a[i] != a[len_a-i-1]:
            return False
    return True


if __name__ == "__main__":
    import doctest
    doctest.testmod()
