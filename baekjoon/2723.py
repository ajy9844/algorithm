import operator as op
from functools import reduce
from math import factorial

def ncr(n, r):
    if n < 1 or r < 0 or n < r:
        raise ValueError
    r = min(r, n-r)
    numerator = reduce(op.mul, range(n, n-r, -1), 1)
    denominator = reduce(op.mul, range(1, r+1), 1)
    return numerator // denominator

ROW = COLUMN = 11
ans  = [[0 for i in range(ROW+1)] for j in range(COLUMN+1)]
memo = [[0 for i in range(ROW+1)] for j in range(COLUMN+1)]

n = int(input())
l = []
for i in range(n):
    l.append(int(input()))

max_b = max(l)

for row in range(1, max_b+1):
    memo[row][1] = 1
for n in range(2, max_b+1):
    for k in range(2, n+1):
        memo[n][k] = memo[n-1][k-1] + k * memo[n-1][k]  # S(N,K) = S(N-1,K-1) + K * S(N-1,K)

ans[1][1] = 1
for n in range(2, max_b+1):
    for r in range(1, n+1):
        if n == r:
            for k in range(1, r+1):
                if k == 1:
                    ans[n][r] += memo[n][k]
                else:
                    ans[n][r] += memo[n][k] * factorial(k)
        else:
            ans[n][r] = ncr(n, r) * ans[r][r]

for b in l:
    print(sum(ans[b]))
