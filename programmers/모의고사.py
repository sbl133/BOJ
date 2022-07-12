def solution(answers):
    num = [[], [], []]
    correct = [0, 0, 0]
    for _ in range(10000//5):
        num[0] += [1,2,3,4,5]
    for _ in range(10000//8):
        num[1] += [2,1,2,3,2,4,2,5]
    for _ in range(10000//10):
        num[2] += [3,3,1,1,2,2,4,4,5,5]
    for i, sol in enumerate(answers):
        if num[0][i] == sol:
            correct[0] += 1
        if num[1][i] == sol:
            correct[1] += 1
        if num[2][i] == sol:
            correct[2] += 1
    order = [(correct[0], 1), (correct[1], 2), (correct[2], 3)]
    order.sort(key = lambda x:(-x[0], x[1]))
    maxi = order[0][0]
    answer = []
    for item in order:
        if item[0] == maxi:
            answer.append(item[1])
    return answer