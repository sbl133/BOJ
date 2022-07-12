def solution(brown, yellow):
    highMax = int(yellow ** 0.5)
    for high in range(1, highMax+1):
        if yellow % high == 0:
            width = yellow // high
            if width*2+high*2+4 == brown:
                return [width + 2, high + 2]
    answer = []
    return answer