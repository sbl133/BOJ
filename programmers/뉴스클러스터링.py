from collections import defaultdict
def solution(str1, str2):
    str1 = str1.lower()
    str2 = str2.lower()
    set1 = defaultdict(int)
    set2 = defaultdict(int)
    simul = 0
    for i in range(1, len(str1)):
        key = str1[i-1:i+1]
        if 'a' <= key[0] <= 'z' and 'a'<= key[1] <= 'z':
            set1[key] += 1
    for i in range(1, len(str2)):
        key = str2[i-1:i+1]
        if 'a' <= key[0] <= 'z' and 'a'<= key[1] <= 'z':
            set2[key] += 1
    if len(set1) == 0 and len(set2) == 0:
        simul = 1
    else :
        geo = 0
        hap = 0
        for key in set1:
            if key in set2:
                geo += min(set1[key], set2[key])
            hap += max(set1[key], set2[key])
        for key in set2:
            if key not in set1:
                hap += set2[key]
        simul = geo/hap
    answer = int(simul * 65536)
    return answer