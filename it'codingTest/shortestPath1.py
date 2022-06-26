import heapq

INF = int(1e10)
n, m, c = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    x, y, z = map(int, input().split())
    graph[x].append((z, y))
dist = [INF] * (n + 1)


def dijkstra(start):
    dist[start] = 0
    q = []
    heapq.heappush(q, (0, start))
    while q:
        cost, now = heapq.heappop(q)
        if dist[now] < cost: continue
        for i in graph[now]:
            nextCost = cost + i[0]
            there = i[1]
            if dist[there] > nextCost:
                dist[there] = nextCost
                heapq.heappush(q, (nextCost, there))


dijkstra(c)
resultNum = 0
resultTime = 0
for i in range(n + 1):
    if dist[i] != INF:
        resultNum += 1
        resultTime = max(resultTime, dist[i])
print(resultNum - 1, resultTime)

