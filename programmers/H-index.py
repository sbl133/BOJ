def solution(citations):
    citations.sort(reverse=True)
    dic = dict()
    for i, citation in enumerate(citations):
        dic[citation] = (i+1)
    num = dic[citations[0]]
    for i in range(citations[0], -1, -1):
        if i in dic:
            num = dic[i]
        if i <= num:
            return i
    answer = 0
    return answer