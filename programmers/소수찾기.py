from collections import defaultdict

result = 0
dic = defaultdict(bool)


def checkPrime(num):
    global dic
    sqrt = int(num ** 0.5);
    if num == 0 or num == 1:
        return False
    for i in range(2, sqrt + 1):
        if num % i == 0:
            return False
    if dic[num] == False:
        dic[num] = True
        return True
    return False


def permutation(data, depth, r):
    global result
    if depth == r:
        if checkPrime(int("".join(data[:r]))):
            result += 1
    for i in range(depth, len(data)):
        data[depth], data[i] = data[i], data[depth]
        permutation(data, depth + 1, r)
        data[depth], data[i] = data[i], data[depth]


def solution(numbers):
    number = list(numbers)
    for r in range(1, len(number) + 1):
        permutation(number, 0, r)
    answer = result
    return answer