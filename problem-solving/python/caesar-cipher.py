import string


ALPHA_LEN = len(string.ascii_lowercase)


def caracter_cipher(c, k):
    idx = 0
    if c.isupper():
        idx = string.ascii_uppercase.index(c)
    else:
        idx = string.ascii_lowercase.index(c)

    idx = (idx + k) % ALPHA_LEN

    if c.isupper():
        return string.ascii_uppercase[idx]
    return string.ascii_lowercase[idx]


def caesar_cipher(text, k):
    res = []
    for c in text:
        if c.isalpha():
            res.append(caracter_cipher(c, k))
        else:
            res.append(c)

    return ''.join(res)


if __name__ == '__main__':
    input()  # ignore n
    s = input()
    k = int(input())

    print(caesar_cipher(s, k))
