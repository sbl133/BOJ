import heapq

def solution(lines):
    timeTable = []
    for line in lines:
        timeInfo = line.split()
        timePieces = timeInfo[1].split(':')
        sec, ms = timePieces[2].split('.')
        time = int(ms) + int(sec) * 1000
        time += int(timePieces[1]) * 60 * 1000
        time += int(timePieces[0]) * 60 * 60 * 1000
        timeTable.append((time, 1))
        how = timeInfo[2].replace('s', '')
        li = how.split('.')
        if len(li) == 1:
            timeTable.append((time - int(li[0])*1000 + 1, -1))
        else:
            timeTable.append((time - int(li[0])*1000 - int(li[1]) + 1, -1))
    timeTable.sort()
    back = 0
    count = 0
    result = 0
    for index, value in enumerate(timeTable):
        while timeTable[back][0] < value[0] + 1000:
            if back == len(timeTable)-1:
                break
            if timeTable[back][1] == -1:
                result += 1
                count = max(count, result)
            back += 1
        if value[1] == 1:
            result -= 1
    answer = count
    return answer