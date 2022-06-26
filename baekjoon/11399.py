n = int(input())
values = list(map(int, input().split()))
_sum = 0
result = 0

values.sort()

for value in values:
    _sum += value
    result += _sum

print(result)
