n = int(input())
result = 0
hour = 0
miniute = 0
second = 0
while True:
  second+=1
  if second == 60:
    second = 0
    miniute+=1
  if miniute == 60:
    miniute = 0
    hour += 1
  if hour > n:
    break
  if str(second).__contains__('3'):
    result += 1
  elif str(miniute).__contains__('3'):
    result += 1
  elif str(hour).__contains__('3'):
    result += 1
print(result)
