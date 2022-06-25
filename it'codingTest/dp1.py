n = int(input())
store = list(map(int, input().split()))

cache = [-1] * 1000

cache[0] = store[0]
cache[1] = max(store[0], store[1])


def steal(point):
    if cache[point] != -1:
        return cache[point]
    ret = max(steal(point - 2) + store[point], steal(point - 1))
    cache[point] = ret
    return ret


print(steal(n - 1))
