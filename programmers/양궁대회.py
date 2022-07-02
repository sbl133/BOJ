result = [-1]
diff = 1
flag = True


def compare(apeach, lion):
    apeachScore = 0
    lionScore = 0
    for i in range(11):
        if apeach[i] >= lion[i] and apeach[i] > 0:
            apeachScore += (10 - i)
        elif lion[i] > 0:
            lionScore += (10 - i)
    return lionScore - apeachScore


def overComb(n, r, pos, apeach, lion):
    global diff
    global result
    global flag
    if pos == 11 and r != 0:
        return
    if r == 0:
        ret = compare(apeach, lion)
        if diff < ret:
            diff = ret
            result = lion
            flag = False
        elif diff == ret:
            if flag:
                result = lion
                flag = False
            else:
                for i in range(10, -1, -1):
                    if result[i] > lion[i]:
                        break;
                    elif result[i] < lion[i]:
                        result = lion
                        break;
        return

    overComb(n, r, pos + 1, apeach, lion[:])
    lion[pos] += 1
    overComb(n, r - 1, pos, apeach, lion[:])


def solution(n, info):
    lion = [0] * 11
    overComb(n, n, 0, info, lion)
    answer = result
    return answer