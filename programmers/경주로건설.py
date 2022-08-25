import heapq

def validation(y, x, board):
    n = len(board)
    if 0<=y<n:
        if 0<=x<n:
            if board[y][x] == 0:
                return False
    return True

def dijkstra(board):
    dx = [0,0,1,-1]
    dy = [1,-1,0,0]
    dist = [[987654321]*len(board) for _ in range(len(board))]
    dist[0][0] = 0
    hq = []
    if board[1][0] == 0:
        dist[1][0] = 100
        heapq.heappush(hq, (100, 1, 0, (1, 0)))
    if board[0][1] == 0:
        dist[0][1] = 100
        heapq.heappush(hq, (100, 0, 1, (0, 1)))
    while hq:
        cur = heapq.heappop(hq)
        cost = cur[0]
        curY = cur[1]
        curX = cur[2]
        direc = cur[3]
        if dist[curY][curX] < cost - 600:
            continue
        for i in range(4):
            nextY = curY + dy[i]
            nextX = curX + dx[i]
            if validation(nextY, nextX, board):
                continue
            if (dy[i], dx[i]) == direc:
                nextCost = cost + 100
            else:
                nextCost = cost + 600
            nextDir = (dy[i], dx[i])
            if dist[nextY][nextX] >= nextCost - 600:
                dist[nextY][nextX] = min(dist[nextY][nextX], nextCost)
                heapq.heappush(hq, (nextCost, nextY, nextX, nextDir))
    return dist

def solution(board):
    result = dijkstra(board)
    answer = result[len(board)-1][len(board)-1]
    return answer