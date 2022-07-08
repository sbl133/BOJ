def solution(participant, completion):
    party = dict()
    for i, player in enumerate(participant):
        if player not in party:
            party[player] = 1
        else:
            party[player] += 1
    for player in completion:
        party[player] -= 1
    for i in party:
        if party[i] == 1:
            return i