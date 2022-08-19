from collections import defaultdict
from collections import deque
import copy

def permutation(li, depth, ret):
    if depth == len(li):
        ret.append(li)
        return ret
    for i in range(depth, len(li)):
        li[i], li[depth] = li[depth], li[i]
        permutation(li[:], depth + 1, ret)
    return ret

def validation(y, x, length):
    if y < 0 or length <= y:
        return False
    if x < 0 or length <= x:
        return False
    return True

def bfs(curPos, desPos, board):
    if curPos == desPos:
        return 0
    dy = [0, 0, -1, 1]
    dx = [1, -1, 0, 0]
    length = len(board)
    visited = [[False] * len(board) for _ in range(len(board))]
    q = deque()
    visited[curPos[0]][curPos[1]] = True
    q.append((curPos, 0))
    while q:
        curPos, curCost = q.popleft()
        if curPos == desPos:
            return curCost
        for i in range(8):
            if 0 <= i < 4:
                nextY, nextX = curPos[0] + dy[i], curPos[1] + dx[i]
                if validation(nextY, nextX, length) and visited[nextY][nextX] == False:
                    visited[nextY][nextX] = True
                    q.append(((nextY, nextX), curCost + 1))
            elif 4 <= i < 8:
                nextY, nextX = curPos[0] + dy[i % 4], curPos[1] + dx[i % 4]
                while validation(nextY, nextX, length) and board[nextY][nextX] == 0:
                    nextY, nextX = nextY + dy[i % 4], nextX + dx[i % 4]
                if not validation(nextY, nextX, length):
                    nextY, nextX = nextY - dy[i % 4], nextX - dx[i % 4]
                if validation(nextY, nextX, length) and visited[nextY][nextX] == False:
                    visited[nextY][nextX] = True
                    q.append(((nextY, nextX), curCost + 1))

def solution(board, r, c):
    dic = defaultdict(list)
    for i in range(len(board)):
        for j in range(len(board)):
            if board[i][j] > 0:
                dic[board[i][j]].append((i, j))
    li = []
    for key in dic:
        li.append(dic[key])
    orders = permutation(li, 0, [])
    answer = 987654321
    for order in orders:
        boardTmp = copy.deepcopy(board)
        cache = [[0] * 2 for _ in range(len(order))]
        curPos = (r, c)
        cache[0][0] = bfs(curPos, order[0][0], boardTmp) + bfs(order[0][0], order[0][1], boardTmp)
        cache[0][1] = bfs(curPos, order[0][1], boardTmp) + bfs(order[0][1], order[0][0], boardTmp)
        boardTmp[order[0][0][0]][order[0][0][1]] = 0
        boardTmp[order[0][1][0]][order[0][1][1]] = 0
        for i in range(1, len(order)):
            cache[i][0] = min(cache[i - 1][0] + bfs(order[i - 1][1], order[i][0], boardTmp),
                              cache[i - 1][1] + bfs(order[i - 1][0], order[i][0], boardTmp)) \
                          + bfs(order[i][0], order[i][1], boardTmp)
            cache[i][1] = min(cache[i - 1][0] + bfs(order[i - 1][1], order[i][1], boardTmp),
                              cache[i - 1][1] + bfs(order[i - 1][0], order[i][1], boardTmp)) \
                          + bfs(order[i][1], order[i][0], boardTmp)
            boardTmp[order[i][0][0]][order[i][0][1]] = 0
            boardTmp[order[i][1][0]][order[i][1][1]] = 0
        answer = min(answer, cache[len(order) - 1][0], cache[len(order) - 1][1])
    return answer + 2 * len(order)