def comb(n, r, depth, user_id, select, ret):
    if r == n:
        ret.append(select)
        return
    if depth == len(user_id):
        return
    comb(n, r, depth + 1, user_id, select[:], ret)
    select.append(user_id[depth])
    comb(n, r + 1, depth + 1, user_id, select[:], ret)


def permu(n, r, items, ret):
    if r == n:
        ret.append(items)
        return
    for i in range(r, n):
        items[i], items[r] = items[r], items[i]
        permu(n, r + 1, items[:], ret)


def solution(user_id, banned_id):
    sets = []
    banned_id.sort()
    comb(len(banned_id), 0, 0, user_id, [], sets)
    answer = 0
    for se in sets:
        cases = []
        permu(len(se), 0, se, cases)
        flag = False
        for li in cases:
            fflag = True
            for i, item in enumerate(li):
                if len(item) != len(banned_id[i]):
                    fflag = False
                    break
                for j in range(len(item)):
                    if item[j] != banned_id[i][j] and banned_id[i][j] != '*':
                        fflag = False
                        break
                if fflag == False:
                    break
            if fflag == True:
                flag = True
                break
        if flag == True:
            print(se)
            answer += 1
    return answer