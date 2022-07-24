def solution(s):
    string = list(s)
    answer = len(s)
    for zipLen in range(1, (len(string)//2)+1):
        newString = []
        match = ''
        num = 1
        for start in range(0, len(string), zipLen):
            comp = string[start:start+zipLen]
            if match == comp:
                num += 1
            else:
                if num != 1:
                    newString += list(str(num)) + comp
                else:
                    newString += comp
                num = 1
                match = comp
        if num > 1:
            newString += list(str(num))
        answer = min(answer, len(newString))
    return answer