from collections import defaultdict
def solution(nums):
    dic = defaultdict(int)
    for num in nums:
        dic[num] += 1
    return min(len(dic), len(nums)//2)