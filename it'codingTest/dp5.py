n = int(input())
soldiers = list(map(int, input().split()))

cache = [-1] * n


def dp(cur):
    if cache[cur] != -1:
        return cache[cur]
    ret = 1
    for i in range(cur, n):
        if soldiers[i] < soldiers[cur]:
            ret = max(ret, dp(i) + 1)
            cache[cur] = ret
    return ret


result = 0
for i in range(n):
    result = max(result, dp(i))
print(n - result)


