n, k = map(int, input().split())
values = []
result = 0
rest_k = k

for i in range(n):
    value = int(input())
    values.append(value)

for value in reversed(values):
    if value <= rest_k:
        q = rest_k // value
        rest_k -= value * q
        result += q
        if rest_k == 0:
            break

print(result)
