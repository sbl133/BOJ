def dfs(adj, visited, here):
    visited[here] = True
    for there in adj[here]:
        if visited[there] == False:
            dfs(adj, visited, there)

def solution(n, wires):
    answer = n
    for i in range(len(wires)):
        adj = [[] for _ in range(n+1)]
        for j in range(len(wires)):
            if i == j:
                continue
            adj[wires[j][0]].append(wires[j][1])
            adj[wires[j][1]].append(wires[j][0])
        visited = [False] * (n+1)
        dfs(adj, visited, 1)
        trueNum = 0
        falseNum = -1
        for state in visited:
            if state == True:
                trueNum += 1
            else:
                falseNum += 1
        answer = min(answer, abs(trueNum-falseNum))
    return answer