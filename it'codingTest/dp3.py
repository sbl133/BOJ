n, m = map(int, input().split())
bils = [0]*n

cache = [-1]*10000
cache[0] = 0

for i in range(n):
  bils[i] = int(input())

def change(cur):
  if cur < 0:
    return 10001
  if cache[cur] != -1:
    return cache[cur]
  ret = 10001
  for bil in bils:
    nextMoney = cur - bil
    ret = min(ret, change(nextMoney)+1)
  cache[cur] = ret
  return ret

result = change(m)
if result == 10001:
  print(-1)
else:
  print(result)

