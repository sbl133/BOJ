testcase = int(input())

for _ in range(testcase):
    n, m = map(int, input().split())
    inputInfo = list(map(int, input().split()))
    board = [[0] * m for _ in range(n)]
    cache = [[-1] * m for _ in range(n)]
    for i in range(n):
        board[i] = inputInfo[i * m:(i + 1) * m]
    for i in range(n):
        cache[i][m - 1] = board[i][m - 1]


    def dp(x, y):
        if cache[y][x] != -1:
            return cache[y][x]
        ret = 0
        if y > 0:
            ret = max(ret, board[y][x] + dp(x + 1, y - 1))
        if y < n - 1:
            ret = max(ret, board[y][x] + dp(x + 1, y + 1))
        ret = max(ret, board[y][x] + dp(x + 1, y))
        cache[y][x] = ret
        return ret


    result = 0
    for i in range(n):
        result = max(result, dp(0, i))

    print(result)
