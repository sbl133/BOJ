def solution(phone_book):
    dic = {}
    phone_book.sort(key = lambda x:len(x))
    for num in phone_book:
        li = list(num)
        string = ''
        for i in li:
            string = string+i
            if string in dic:
                return False
        dic[num] = True
    return True