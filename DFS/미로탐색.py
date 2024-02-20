from collections import deque

N, M = map(int, input().split())

m = []


for _ in range(N):
    m.append(list(map(int, input())))


def bfs(start):
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    q = deque([(0, 0)])
    while deque:
        x, y = q.popleft()
        if x == N-1 and y == M-1:
            print(m[x][y])
            return
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue
            if m[nx][ny] == 0:
                continue
            if m[nx][ny] == 1:
                m[nx][ny] = m[x][y]+1
                q.append((nx, ny))


bfs((0, 0))
