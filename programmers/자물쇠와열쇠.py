from collections import defaultdict
from collections import deque

def circle(board):
    length = len(board)
    ret = [[0]*length for _ in range(length)]
    for i in range(length):
        for j in range(length):
            ret[j][length-i-1] = board[i][j]
    return ret

def check(key, lock, n):
    for i in range(n):
        for j in range(n):
            if lock[i][j] == 0:
                if key[i][j] != 1:
                    return False
            elif lock[i][j] == 1:
                if key[i][j] != 0:
                    return False
    return True

def bfs(key, lock, n):
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]
    if check(key, lock, n):
        return True
    visited = defaultdict(bool)
    visited[(0,0)] = True
    dq = deque()
    dq.append(((0,0), key))
    while dq:
        front = dq.popleft()
        curY = front[0][0]
        curX = front[0][1]
        for i in range(4):
            nextY = curY + dy[i]
            nextX = curX + dx[i]
            if -n < nextY < n and -n < nextX < n and visited[(nextY, nextX)] == False:
                nextKey = [[0]*n for _ in range(n)]
                tempKey = [[0]*n for _ in range(n)]
                for i in range(n):
                    iterY = nextY + i
                    if iterY < 0:
                        continue
                    if iterY >= n:
                        break
                    for j in range(n):
                        tempKey[iterY][j] = key[i][j]
                for i in range(n):
                    iterX = nextX + i
                    if iterX < 0:
                        continue
                    if iterX >= n:
                        break
                    for j in range(n):
                        nextKey[j][iterX] = tempKey[j][i]
                if check(nextKey, lock, n):
                    return True
                else:
                    visited[(nextY, nextX)] = True
                    dq.append(((nextY, nextX), nextKey))
    return False

def solution(key, lock):
    m = len(key)
    n = len(lock)
    for _ in range(4):
        key = circle(key)
        onKey = [[0]*n for _ in range(n)]
        for i in range(m):
            for j in range(m):
                onKey[i][j] = key[i][j]
        if bfs(onKey, lock, n):
            return True
    return False