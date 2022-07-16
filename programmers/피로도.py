answer = 0
def recursion(dungeons, start, tired, visitNum):
    global answer
    if start == len(dungeons):
        return visitNum
    for i in range(start, len(dungeons)):
        dungeons[start], dungeons[i] = dungeons[i], dungeons[start]
        if dungeons[start][0] > tired:
            answer = max(answer, recursion(dungeons[:], start+1, tired, visitNum))
        else:
            answer = max(answer, recursion(dungeons[:], start+1, tired - dungeons[start][1], visitNum+1))
        dungeons[start], dungeons[i] = dungeons[i], dungeons[start]
    return answer

def solution(k, dungeons):
    return recursion(dungeons, 0, k, 0)
