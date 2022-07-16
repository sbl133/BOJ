order = 1
def recursion(aeiou, string, dic, depth):
    global order
    if depth == 5:
        return
    for alpha in aeiou:
        new = string + alpha
        dic[new] = order
        order += 1
        recursion(aeiou, new, dic, depth+1)

def solution(word):
    aeiou = ['A', 'E', 'I', 'O', 'U']
    string = ''
    dic = dict()
    recursion(aeiou, string, dic, 0)
    answer = dic[word]
    return answer