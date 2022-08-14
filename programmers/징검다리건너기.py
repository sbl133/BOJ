def biConq(stones, left, right, k):
    if right - left + 1 < k:
        return 987654321
    elif right - left + 1 == k:
        return max(stones[left:right+1])
    mid = (left + right) // 2
    ret = min(biConq(stones, left, mid, k), biConq(stones, mid+1, right, k))
    i, j = mid, mid+1
    maxi = max(stones[mid], stones[mid+1])
    while j - i + 1 < k:
        if j < right and (i==left or stones[j+1] < stones[i-1]):
            maxi = max(maxi, stones[j+1])
            j += 1
        else:
            maxi = max(maxi, stones[i-1])
            i -= 1
    ret = min(ret, maxi)
    return ret

def solution(stones, k):
    if len(stones) == 1:
        return stones[0]
    answer = biConq(stones, 0, len(stones)-1, k)
    return answer