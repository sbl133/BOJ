from collections import deque
from collections import defaultdict
import sys
sys.setrecursionlimit(10**6)

def preorder(tree, cur, ret):
    if cur == 0:
        return
    ret.append(cur)
    preorder(tree, tree[cur][0], ret)
    preorder(tree, tree[cur][1], ret)
    return ret

def postorder(tree, cur, ret):
    if cur == 0:
        return
    postorder(tree, tree[cur][0], ret)
    postorder(tree, tree[cur][1], ret)
    ret.append(cur)
    return ret

def solution(nodeinfo):
    if len(nodeinfo) == 1:
        return [[1],[1]]
    nodeInfo = []
    for i, node in enumerate(nodeinfo):
        nodeInfo.append([i+1, node[0], node[1]])
    nodeInfo.sort(key = lambda x:(-x[2], x[1]))
    head = nodeInfo[0][0]
    tree = defaultdict(lambda :[0,0])
    dq = deque()
    dq.append(nodeInfo[0]+[100000])
    nodeInfo.pop(0)
    parentLevel = dq[0][2]
    childLevel = nodeInfo[0][2]
    for node in nodeInfo:
        if childLevel != node[2]:
            while dq and dq[0][2] == parentLevel:
                dq.popleft()
            childLevel = node[2]
            parentLevel = dq[0][2]
        while dq and node[1] > dq[0][3]:
            dq.popleft()
        if node[1] < dq[0][1]:
            tree[dq[0][0]][0] = node[0]
            dq.append(node + [dq[0][1]])
        else:
            tree[dq[0][0]][1] = node[0]
            dq.append(node + [dq[0][3]])
            dq.popleft()
    answer = []
    answer.append(preorder(tree, head, []))
    answer.append(postorder(tree, head, []))
    return answer