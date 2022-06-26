n = int(input())
times = []
result = 0

for i in range(n):
    _time = tuple(map(int, input().split()))
    times.append(_time)

sorted_times = sorted(times, key=lambda x: (x[1], x[0]))

last_t = sorted_times[n - 1][1]
check = [True for _ in range(last_t + 1)]
pre_end_t = -1
cur_str_t = -1

for _time in sorted_times:
    cur_str_t = _time[0]
    if pre_end_t > cur_str_t:
        continue
    pre_end_t = _time[1]
    result += 1

print(result)
