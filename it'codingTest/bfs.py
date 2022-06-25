from collections import deque

q = deque()
print(q)

n, m = map(int, input().split())

board = [[0] * m for _ in range(n)]

for i in range(n):
    board[i] = list(input())

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]


def checkValid(x, y):
    if x < 0 or x >= m:
        return False
    if y < 0 or y >= n:
        return False
    if board[y][x] == 0:
        return False
    return True


def bfs():
    queue = deque()
    board[0][0] = 0
    queue.append((0, 0, 1))
    while queue:
        (y, x, dist) = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            ndist = dist + 1
            if checkValid(nx, ny):
                if nx == m - 1 and ny == n - 1:
                    return ndist
                queue.append((ny, nx, ndist))
                board[ny][nx] = 0


print(bfs())
