from collections import defaultdict

# li의 index, 선택한 개수, 선택한 것들, 의류 정보, 의류 종류
def comb(index, r, select, dic, li):
    if r == 0:
        return select
    if index == len(li):
        return 0
    ret = 0
    ret += comb(index + 1, r, select, dic, li)
    ret += comb(index + 1, r - 1, select * dic[li[index]], dic, li)
    return ret


def solution(clothes):
    dic = dict()
    for i in clothes:
        if i[1] not in dic:
            dic[i[1]] = 0
        dic[i[1]] += 1
    # li = []
    # for i in dic:
    #     li.append(i)
    # for i in range(1, len(dic)+1):
    #     answer += comb(0, i, 1, dic, li)
    answer = 1
    for i in dic:
        answer *= (dic[i] + 1)
    answer -= 1
    return answer