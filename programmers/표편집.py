class LinkedList:
    class Node:
        def __init__(self, num, prev):
            self.num = num
            self.prev = prev
            self.next = None

    def __init__(self, num, start):
        self.root = self.Node(0, None)
        self.current = None
        self.stack = []
        temp = self.root
        for i in range(1, num):
            new_node = self.Node(i, temp)
            temp.next = new_node
            if i == start:
                self.current = new_node
            temp = new_node

    def up(self, num):
        for _ in range(num):
            if self.current.prev:
                self.current = self.current.prev

    def down(self, num):
        for _ in range(num):
            if self.current.next:
                self.current = self.current.next

    def remove(self):
        remove_node = self.current
        self.stack.append(remove_node)
        if remove_node.next:
            if remove_node == self.root:
                self.root = remove_node.next
            self.current = remove_node.next
            self.current.prev = remove_node.prev
            if remove_node.prev:
                remove_node.prev.next = self.current
        else:
            self.current = remove_node.prev
            self.current.next = None

    def recover(self):
        recover_node = self.stack.pop()
        if recover_node.prev:
            recover_node.prev.next = recover_node
        if recover_node.next:
            recover_node.next.prev = recover_node
            if recover_node.next == self.root:
                self.root = recover_node

    def get_root(self):
        return self.root


def solution(n, k, cmd):
    table = LinkedList(n, k)
    for c in cmd:
        if c[0] == 'U':
            table.up(int(c.split()[1]))
        elif c[0] == 'D':
            table.down(int(c.split()[1]))
        elif c[0] == 'C':
            table.remove()
        else:
            table.recover()
    node = table.get_root()
    result = ["X"] * n
    while node:
        result[node.num] = "O"
        node = node.next
    return "".join(result)