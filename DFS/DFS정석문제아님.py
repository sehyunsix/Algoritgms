"""
1260. DFS와 BFS
"""
from sys import stdin


n, m, v = map(int, stdin.readline().split())
visited = [False] * (n + 1)
g: list = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, stdin.readline().split())
    g[a].append(b)
    g[b].append(a)


dfs_paths = []
bfs_paths = []


def dfs(x):
    visited[x] = True
    dfs_paths.append(x)

    for gx_i in sorted(g[x]):
        if not visited[gx_i]:
            dfs(gx_i)


def bfs(x):
    check[x] = True
    q = [x]

    while q:
        x_i = q.pop(0)
        bfs_paths.append(x_i)

        for gx_i in sorted(g[x_i]):
            if not check[gx_i]:
                check[gx_i] = True
                q.append(gx_i)


dfs(v)
check = [False] * (n + 1)
bfs(v)

print(*dfs_paths)
print(*bfs_paths)
