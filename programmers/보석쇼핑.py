from collections import defaultdict


def solution(gems):
    totalDic = dict()
    for gem in gems:
        totalDic[gem] = True
    front = 0
    back = 0
    minimum = 100000
    answer = []
    dic = defaultdict(int)
    while front < len(gems):
        while len(dic) != len(totalDic) and front < len(gems):
            dic[gems[front]] += 1
            front += 1
        while len(dic) == len(totalDic):
            if minimum > front - back:
                minimum = front - back
                answer = [back + 1, front]
            dic[gems[back]] -= 1
            if dic[gems[back]] == 0:
                dic.pop(gems[back])
            back += 1

    return answer