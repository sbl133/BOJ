import heapq
def makeGraph(n, fares):
    adj = [[987654321]*(n+1) for _ in range(n+1)]
    for i in range(1, n+1):
        adj[i][i] = 0
    for fare in fares:
        adj[fare[0]][fare[1]] = fare[2]
        adj[fare[1]][fare[0]] = fare[2]
    return adj

def floyd(adj, n):
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j])

def solution(n, s, a, b, fares):
    adj = makeGraph(n, fares)
    floyd(adj, n)
    answer = 987654321
    for i in range(1, n+1):
        tmp = adj[s][i] + adj[i][a] + adj[i][b]
        answer = min(answer, tmp)
    return answer