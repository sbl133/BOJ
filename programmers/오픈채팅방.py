def solution(record):
    inout = []
    nickName = dict()
    for rec in record:
        li = list(rec.split())
        if len(li) == 3:
            kind, uid, nick = li
            nickName[uid] = nick
            if kind == "Enter":
                inout.append((kind, uid))
        else:
            kind, uid = li
            inout.append((kind, uid))
    answer = []
    for io in inout:
        kind, uid = io
        name = nickName[uid]
        if kind == "Enter":
            string = name + "님이 들어왔습니다."
        else:
            string = name + "님이 나갔습니다."
        answer.append(string)
    return answer