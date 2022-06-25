n, m = map(int, input().split())

dx = [0, 0, 1, -1]
dy = [-1, 1, 0, 0]

board = [[0]*m for _ in range(n)]
visited = [[False]*m for _ in range(n)]
result = 0

for i in range(n):
  board[i] = list(map(int, input()))

print(board)

def checkValid(x, y):
  if x<0 or x>=m:
    return False
  if y<0 or y>=n:
    return False
  if board[y][x]==1:
    return False
  return True

def dfs(x, y):
  visited[y][x] = True
  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]
    if checkValid(nx, ny) and not visited[ny][nx]:
      visited[ny][nx] = True
      dfs(nx, ny)


for y in range(n):
  for x in range(m):
    if not visited[y][x] and board[y][x] == 0:
      result += 1
      dfs(x, y)
print(result)