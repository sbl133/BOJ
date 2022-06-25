n, m = map(int, input().split())
dduck = list(map(int, input().split()))

max_init = 1000000000
min_init = 0
result = 0


def cut(mini, maxi):
  global result
  if mini > maxi:
    return result
  mid = (mini+maxi) // 2
  cutted = 0
  for i in dduck:
    if (i - mid) > 0:
      cutted += (i-mid)
  if cutted >= m:
    result = max(result, mid)
    return cut(mid+1, maxi)
  else:
    return cut(mini, mid-1)

print(cut(min_init, max_init))
