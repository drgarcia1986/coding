arr = [
    [int(i) for i in input().rstrip().split()]
    for _ in range(6)
]

high = -100
for i in range(len(arr) - 2):
    for j in range(len(arr[i]) - 2):
        actual = sum([
            arr[i][j], arr[i][j+1], arr[i][j+2],
            arr[i+1][j+1],
            arr[i+2][j], arr[i+2][j+1], arr[i+2][j+2]
        ])
        if actual > high:
            high = actual
print(high)
