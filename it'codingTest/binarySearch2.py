n, x = map(int, input().split())
sortedList = list(map(int, input().split()))

def searchX(mini, maxi):
  if mini > maxi:
    return -1
  mid = (mini+maxi) // 2
  if sortedList[mid] == x:
    return mid
  elif sortedList[mid] > x:
    return searchX(mini, mid-1)
  else:
    return searchX(mid+1, maxi)

def searchMin(index):
  while index>0:
    if sortedList[index]==x:
      index -= 1
    else:
      return index+1
  return 0

def searchMax(index):
  while index<n:
    if sortedList[index] == x:
      index += 1
    else :
      return index-1
  return n-1

index = searchX(0, n-1)
if index == -1:
  print(-1)
else:
  mini = searchMin(index)
  maxi = searchMax(index)
  print(mini)
  print(maxi)
  print(maxi-mini+1)
