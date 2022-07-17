from collections import deque
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def validation(x, y, maps):
    if 0 > x or x >= len(maps[0]):
        return False
    if 0 > y or y >= len(maps):
        return False
    return True

def bfs(maps):
    dq = deque()
    dq.append((0, 0, 1))
    while dq:
        curX, curY, dist = dq.popleft()
        if curX == len(maps[0])-1 and curY == len(maps)-1:
            return dist
        for i in range(4):
            nextX = curX + dx[i]
            nextY = curY + dy[i]
            if validation(nextX, nextY, maps) and maps[nextY][nextX] == 1:
                maps[nextY][nextX] = 0
                dq.append((nextX, nextY, dist + 1))
    return -1

def solution(maps):
    return bfs(maps)
