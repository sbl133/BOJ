def calcTime(li):
    li = li.split(':')
    return 60 * 60 * int(li[0]) + 60 * int(li[1]) + int(li[2])

def solution(play_time, adv_time, logs):
    calced_play_time = calcTime(play_time)
    running_time = [0] * (calced_play_time+1)
    calced_adv_time = calcTime(adv_time)
    for log in logs:
        start, end = log.split('-')
        calced_start = calcTime(start)
        calced_end = calcTime(end)
        running_time[calced_start] += 1
        running_time[calced_end] -= 1
    for i in range(1, len(running_time)):
        running_time[i] = running_time[i] + running_time[i-1]
    maxTime ,curTime, result = 0, 0, 0
    for i in range(calced_adv_time):
        curTime += running_time[i]
    maxTime = curTime
    for i in range(calced_adv_time, len(running_time)):
        curTime -= running_time[i-calced_adv_time]
        curTime += running_time[i]
        if maxTime < curTime:
            maxTime = curTime
            result = i-calced_adv_time + 1
    hh = result // 3600
    result = result % 3600
    mm = result // 60
    result = result % 60
    ss = result
    answer = str(hh).zfill(2) + ':' + str(mm).zfill(2) + ':' + str(ss).zfill(2)
    return answer