def canGidoung(gidoung, bo, x, y, n):
    if y == 0 or gidoung[x][y-1] or bo[x][y] or bo[x-1][y]:
        return True
    return False

def canBo(gidoung, bo, x, y, n):
    if gidoung[x][y-1] or gidoung[x+1][y-1]:
        return True
    if bo[x-1][y] and bo[x+1][y]:
        return True
    return False

def solution(n, build_frame):
    gidoung = [[False]*(n+1) for _ in range(n+1)]
    bo = [[False]*(n+1) for _ in range(n+1)]
    for cur in build_frame:
        x, y, kind, how = cur[0], cur[1], cur[2], cur[3]
        if kind == 0:
            if how == 1:
                if canGidoung(gidoung, bo, x, y, n):
                    gidoung[x][y] = True
            elif how == 0:
                gidoung[x][y] = False
                if bo[x-1][y+1] and not canBo(gidoung, bo, x-1, y+1, n):
                    gidoung[x][y] = True
                    continue
                if bo[x][y+1] and not canBo(gidoung, bo, x, y+1, n):
                    gidoung[x][y] = True
                    continue
                if gidoung[x][y+1] and not canGidoung(gidoung, bo, x, y+1, n):
                    gidoung[x][y] = True
                    continue
        elif kind == 1:
            if how == 1:
                if canBo(gidoung, bo, x, y, n):
                    bo[x][y] = True
            elif how == 0:
                bo[x][y] = False
                if gidoung[x][y] and not canGidoung(gidoung, bo, x, y, n):
                    bo[x][y] = True
                    continue
                if gidoung[x+1][y] and not canGidoung(gidoung, bo, x+1, y, n):
                    bo[x][y] = True
                    continue
                if bo[x-1][y] and not canBo(gidoung, bo, x-1, y, n):
                    bo[x][y] = True
                    continue
                if bo[x+1][y] and not canBo(gidoung, bo, x+1, y, n):
                    bo[x][y] = True
                    continue
    answer = []
    for i in range(n+1):
        for j in range(n+1):
            if gidoung[i][j]:
                answer.append([i,j,0])
            if bo[i][j]:
                answer.append([i,j,1])
    return answer