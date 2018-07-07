import sys


n = input()
book = dict(input().split() for _ in range(int(n)))

for line in sys.stdin:
    query = line.strip()
    if query in book:
        print('{}={}'.format(query, book[query]))
    else:
        print('Not found')
