from collections import defaultdict
def solution(n, t, m, timetable):
    dic = defaultdict()
    for i, time in enumerate(timetable):
        hh, mm = time.split(':')
        timetable[i] = int(hh)*60 + int(mm)
    timetable.sort()
    it = 0
    for i in range(n):
        busTime = 540 + t*i
        people = []
        while it < len(timetable) and timetable[it] <= busTime and len(people) < m:
            people.append(timetable[it])
            it += 1
        dic[busTime] = people
    result = 0
    last = 540 + t * (n-1)
    if len(dic[last]) == m:
        result = dic[last][-1]-1
    else:
        result = last
    hour = result // 60
    miniute = result % 60
    answer = str(hour).zfill(2) + ':' + str(miniute).zfill(2)
    return answer