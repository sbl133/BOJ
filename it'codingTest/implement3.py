def checkValidation(x, y):
  if x<1 or x>8:
    return False
  if y<1 or y>8:
    return False
  return True

board = {"a": 1, "b": 2, "c": 3, "d": 4, "e": 5, "f": 6, "g": 7, "h":8}
dx = [-2, -2, 2, 2, -1, -1, 1, 1]
dy = [-1, 1, -1, 1, 2, -2, 2, -2]
coordi = list(input())
curY = int(coordi[1])
curX = board[coordi[0]]
result = 0
for dir in range(8):
  nextX = curX + dx[dir]
  nextY = curY + dy[dir]
  if checkValidation(nextX, nextY):
    result += 1
print(result)