x = int(input())

cache = [-1]*30001
cache[1] = 0

def impl(param):
  if cache[param] != -1:
    return cache[param]
  case1 = x
  case2 = x
  case3 = x
  case4 = x
  if param % 5 == 0:
    case1 = 1 + impl(param//5)
  if param % 3 == 0:
    case2 = 1 + impl(param//3)
  if param % 2 ==0:
    case3 = 1 + impl(param//2)
  case4 = 1 + impl(param-1)
  ret = min(case1, case2, case3, case4)
  cache[param] = ret
  return ret

print(impl(x))