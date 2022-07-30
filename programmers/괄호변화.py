def recursion(p):
    if not p:
        return ""
    u = ""
    op = 0
    cl = 0
    flag = True
    for index, i in enumerate(p):
        u += i
        if i == '(':
            op += 1
        else:
            cl += 1
        if op < cl:
            flag = False
        if op == cl:
            if flag:
                return u + recursion(p[index + 1:])
            else:
                temp = u[1:-1]
                last = ""
                for j in temp:
                    if j == '(':
                        last += ')'
                    else:
                        last += '('
                return "(" + recursion(p[index + 1:]) + ")" + last


def solution(p):
    return recursion(p)