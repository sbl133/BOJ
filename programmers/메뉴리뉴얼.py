from collections import defaultdict
def comb(order, r, depth, cnt, select, ret):
    if cnt == r:
        ret.append(select)
        return
    if depth == len(order):
        return
    comb(order, r, depth+1, cnt, select[:], ret)
    select.append(order[depth])
    comb(order, r, depth+1, cnt+1, select[:], ret)
    return ret

def solution(orders, course):
    orderList = []
    answer = []
    for order in orders:
        order = list(order)
        order.sort()
        orderList.append(order)
    for num in course:
        menu = defaultdict(int)
        for order in orderList:
            candi = comb(order, num, 0, 0, [], [])
            for cand in candi:
                key = "".join(cand)
                menu[key] += 1
        sortedMenu = sorted(menu.items(), key = lambda x:x[1], reverse=True)
        if len(sortedMenu) > 1 and sortedMenu[0][1] > 1:
            for item in sortedMenu:
                if item[1] == sortedMenu[0][1]:
                    answer.append(item[0])
                else:
                    break
    answer.sort()
    return answer