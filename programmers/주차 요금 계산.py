import math


def calcTime(inTime, outTime):
    inHour, inMinute = map(int, inTime.split(':'))
    outHour, outMinute = map(int, outTime.split(':'))
    hour = outHour - inHour
    minute = outMinute - inMinute
    result = hour * 60 + minute
    return result


def solution(fees, records):
    answer = []
    basicUnit, basicCost, addUnit, addCost = fees
    recordInfo = {}
    for record in records:
        time, carNum, inOut = record.split()
        if recordInfo.get(carNum) == None:
            recordInfo[carNum] = [(time, inOut)]
        else:
            recordInfo[carNum].append((time, inOut))
    recordInfo = sorted(recordInfo.items())
    totalTime = []
    for record in recordInfo:
        curTime = 0
        carNum = record[0]
        inOutInfo = record[1]
        totalMinute = 0
        intime = ""
        outtime = ""
        for i in range(len(inOutInfo)):
            time = inOutInfo[i][0]
            inout = inOutInfo[i][1]
            if inout == "IN":
                intime = time
                if i == len(inOutInfo) - 1:
                    curTime += calcTime(intime, "23:59")
            else:
                outtime = time
                curTime += calcTime(intime, outtime)
        if curTime <= basicUnit:
            answer.append(basicCost)
        else:
            result = basicCost
            curTime -= basicUnit
            curTime = curTime / addUnit
            curTime = math.ceil(curTime)
            result += curTime * addCost
            answer.append(result)

    return answer