strToList = list(map(int, input()))
sorted(strToList)
result = 0
for i in range(len(strToList)):
    if result == 0 or strToList[i] == 1:
        result = result + strToList[i]
    else:
        result = result * strToList[i]

print(result)
