def checkValidation(x, y):
  if x < 1 or x > n:
    return False
  if y < 1 or y > n:
    return False
  return True

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
n = int(input())
plan = input().split()

curX=1
curY=1

for dir in plan:
  if dir == 'D':
    nextX = curX + dx[0]
    nextY = curY + dy[0]
  elif dir == 'U':
    nextX = curX + dx[1]
    nextY = curY + dy[1]
  elif dir == 'R':
    nextX = curX + dx[2]
    nextY = curY + dy[2]
  else:
    nextX = curX + dx[3]
    nextY = curY + dy[3]
  if checkValidation(nextX, nextY):
    curX = nextX
    curY = nextY
print(f"{curY} {curX}")



