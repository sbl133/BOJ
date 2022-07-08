from collections import defaultdict
def solution(genres, plays):
    genresDict = defaultdict(int)
    playsDict = defaultdict(list)
    for i, genre in enumerate(genres):
        genresDict[genre] += plays[i]
    sortedGenresDict = sorted(genresDict.items(), key = lambda x:x[1], reverse=True)
    for i, genre in enumerate(genres):
        playsDict[genre].append((plays[i], i))
    for key in playsDict:
        playsDict[key].sort(key = lambda x:(-x[0],x[1]))
    answer = []
    for item in sortedGenresDict:
        answer.append(playsDict[item[0]][0][1])
        if len(playsDict[item[0]]) >= 2:
            answer.append(playsDict[item[0]][1][1])
    return answer