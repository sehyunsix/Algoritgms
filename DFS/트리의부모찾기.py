from collections import deque



'''
시간 초과 풀이
'''
n = int(input())

g = {}
g[1] = -1
stack = []
for _ in range(n - 1):
    a, b = map(int, input().split())
    if a == 1:
        g[b] = 1
    elif b == 1:
        g[a] = 1
    elif not (a in g) and not (b in g):
        stack.append((a, b))
    elif a not in g:
        g[a] = b
    elif b not in g:
        g[b] = a

deq = deque(stack[:])
while deq:
    s = deq.popleft()
    a, b = s
    if a not in g:
        g[a] = b
    elif b not in g:
        g[b] = a
    else:
        deq.append(s)


g = dict(sorted(g.items()))
for v in list(g.values())[1:]:
    print(v)
