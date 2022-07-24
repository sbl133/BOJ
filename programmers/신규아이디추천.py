def step1(strList):
    for i in range(len(strList)):
        diff = ord('a') - ord('A')
        if ord('A') <= ord(strList[i]) <= ord('Z'):
            strList[i] = chr(ord(strList[i]) + diff)


def step2(strList):
    index = 0
    while (True):
        if index == len(strList):
            break
        if 'a' <= strList[index] <= 'z' or '0' <= strList[index] <= '9' or strList[index] == '-' or strList[
            index] == '_' or strList[index] == '.':
            index += 1
        else:
            del strList[index]


def step3(strList):
    index = 1
    while (True):
        if index == len(strList):
            break
        if strList[index - 1] == '.' and strList[index] == '.':
            del strList[index]
        else:
            index += 1


def step4(strList):
    if len(strList) == 0:
        return
    if strList[0] == '.':
        del strList[0]
    if len(strList) == 0:
        return
    if strList[len(strList) - 1] == '.':
        del strList[len(strList) - 1]


def step5(strList):
    if len(strList) == 0:
        strList.append('a')


def step6(strList):
    if len(strList) >= 16:
        strList = strList[:15]
        step4(strList)
        print(strList)
        return strList
    return strList


def step7(strList):
    if len(strList) <= 2:
        while (True):
            if len(strList) == 3:
                break
            strList.append(strList[len(strList) - 1])


def solution(new_id):
    strList = list(new_id)
    step1(strList)
    step2(strList)
    step3(strList)
    step4(strList)
    step5(strList)
    strList = step6(strList)
    step7(strList)
    answer = "".join(strList)
    return answer