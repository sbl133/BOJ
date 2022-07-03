def marking(skillBoard, skill):
    for i in skill:
        degree = i[5]
        if i[0] == 1:
            degree *= -1
        skillBoard[i[1]][i[2]] += degree
        if i[3] < len(skillBoard) - 1 and i[4] < len(skillBoard) - 1:
            skillBoard[i[1]][i[4] + 1] -= degree
            skillBoard[i[3] + 1][i[2]] -= degree
            skillBoard[i[3] + 1][i[4] + 1] += degree
        elif i[3] < len(skillBoard) - 1:
            skillBoard[i[3] + 1][i[2]] -= degree
        elif i[4] < len(skillBoard) - 1:
            skillBoard[i[1]][i[4] + 1] -= degree


def calcSkill(skillBoard):
    prev = [0] * len(skillBoard)
    for i in range(len(skillBoard)):
        for j in range(len(skillBoard)):
            skillBoard[j][i] += prev[j]
            prev[j] = skillBoard[j][i]
    prev = [0] * len(skillBoard)
    for i in range(len(skillBoard)):
        for j in range(len(skillBoard)):
            skillBoard[i][j] += prev[j]
            prev[j] = skillBoard[i][j]


def calcResult(skillBoard, board):
    result = 0
    for i in range(len(board)):
        for j in range(len(board[0])):
            board[i][j] += skillBoard[i][j]
            if board[i][j] > 0:
                result += 1
    return result


def solution(board, skill):
    skillBoard = [[0] * len(board[0]) for _ in range(len(board))]
    marking(skillBoard, skill)
    calcSkill(skillBoard)
    answer = calcResult(skillBoard, board)
    return answer