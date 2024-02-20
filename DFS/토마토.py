from collections import deque

N, M = map(int, input().split())
m = []
for _ in range(M):
    m.append(list(map(int, input().split())))


def bfs(start):
    deq = deque(start)
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    while deq:
        x, y = deq.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= M or ny >= N:
                continue
            if m[nx][ny] == -1:
                continue
            if m[nx][ny] == 0:
                m[nx][ny] = m[x][y] + 1
                deq.append((nx, ny))


def find_starts():
    starts = []
    for i in range(M):
        for j in range(N):
            if m[i][j] == 1:
                starts.append((i, j))
    return starts


bfs(find_starts())

check = 1 in [(0 in l) for l in m]
if check:
    print(-1)
else:
    m = [max(l) for l in m]
    answer = max(m)
    print(answer - 1)
