import sys
input = sys.stdin.readline
INF = int(1e10)
n, m = map(int, input().split())
adj = [[INF] * (n+1) for _ in range(n+1)]
for i in range(n+1):
    adj[i][i] = 0
for _ in range(m):
  x, y = map(int, input().split())
  adj[x][y] = 1
  adj[y][x] = 1

x, k = map(int, input().split())

def floyd():
  for i in range(1, n+1):
    for j in range(n+1):
      for k in range(n+1):
        adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k])

floyd()
result = adj[1][k] + adj[k][x]
if result >= INF:
  print("-1")
else:
  print(adj[1][k]+adj[k][x])
