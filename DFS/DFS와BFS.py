from collections import deque

n, m, v = map(int, input().split())
edges = []
for _ in range(m):
    edges.append(list(map(int, input().split())))


class Node:
    def __init__(self, ID):
        self.ID = ID
        self.child = []
        self.visited = False

    def _print(self):
        print(self.ID)


node_dict = {}


root = Node(v)
stack = [root]
node_dict[v] = Node(v)

for edge in edges:
    for i, e in enumerate(edge):
        if e not in node_dict:
            node_dict[e] = Node(e)
    for i, e in enumerate(edge):
        node_dict[e].child.append(node_dict[edge[i - 1]])


def dfs(node):
    if node.child == None:
        return 0
    stack = [node]
    while stack:
        n = stack.pop()
        if n.visited == True:
            continue
        print(n.ID, end=" ")
        n.visited = True
        if n.child:
            n.child.sort(key=lambda x: x.ID, reverse=True)
            for s in n.child:
                stack.append(s)


def bfs(node):
    if node.child == None:
        return 0
    queue = deque([node])
    while queue:
        n = queue.popleft()
        if n.visited == True:
            continue
        print(n.ID, end=" ")
        n.visited = True
        if n.child:
            n.child.sort(key=lambda x: x.ID, reverse=False)
            for s in n.child:
                queue.append(s)


dfs(node_dict[v])
for k, value in node_dict.items():
    value.visited = False
print("")
bfs(node_dict[v])
