def isPrime(num):
    if num == 0 or num == 1:
        return False
    sqr = int(num ** 0.5)
    sqr += 1
    for i in range(2, sqr):
        if num % i == 0:
            return False
    return True


def solution(n, k):
    answer = 0
    changeNum = []
    while n > 0:
        extra = n % k
        changeNum.append(extra)
        n = n // k
    exchangeNum = 0
    digit = 0
    for it in range(len(changeNum)):
        exchangeNum += changeNum[it] * (10 ** digit)
        digit += 1
        if changeNum[it] == 0 or it == len(changeNum) - 1:
            if isPrime(exchangeNum) == True:
                answer += 1
            digit = 0
            exchangeNum = 0

    return answer