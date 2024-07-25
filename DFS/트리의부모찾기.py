from collections import deque
import sys

sys.setrecursionlimit(10**6)
"""
시간 초과 풀이
"""
n = int(input())

g = {}
g[1] = -1
stack = []

for i in range(1, n + 1):
    g[i] = []
for _ in range(n - 1):
    a, b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)
    # a, b = map(int, input().split())
    # if a == 1:
    #     g[b] = 1
    # elif b == 1:
    #     g[a] = 1
    # elif not (a in g) and not (b in g):
    #     stack.append((a, b))
    # elif a not in g:
    #     g[a] = b
    # elif b not in g:
    #     g[b] = a


p = {}
for i in range(1, n + 1):
    p[i] = -1

visited = [False] * (n + 1)


# recursion limit
# def dfs(g, start):
#     visited[start] = True
#     for c in g[start]:
#         if not visited[c]:
#             dfs(g, c)
#         else:
#             p[start] = c
#     return


# stack
def dfs(g, start):
    stack = [start]
    while stack:
        start = stack.pop()
        visited[start] = True
        for c in g[start]:
            if not visited[c]:
                stack.append(c)
            else:
                p[start] = c


# stack.sort(key=lambda x: x[
# deq = deque(stack[:])
# while deq:
#     s = deq.popleft()
#     a, b = s
#     if a not in g:
#         g[a] = b
#     elif b not in g:
#         g[b] = a
#     else:
#         deq.append(s)
dfs(g, 1)
p = dict(sorted(p.items()))
for v in list(p.values())[1:]:
    print(v)
