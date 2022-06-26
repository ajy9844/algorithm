n, m = map(int, input().split())
arr = [[1 for i in range(m+1)] for j in range(n+1)]

for row in range(n+1):
    arr[row][0] = 0
for col in range(m+1):
    arr[0][col] = 0

for row in range(1, n+1):
    for col in range(1, m+1):
        if row == 1 and col == 1:
            arr[row][col] = 1
        else:
            arr[row][col] = arr[row-1][col] + arr[row][col-1] + arr[row-1][col-1]

print(arr[n][m] % 1000000007)