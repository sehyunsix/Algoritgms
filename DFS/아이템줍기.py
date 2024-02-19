


global step,step_list,answer,m,visited,i_x,i_y


def search(start):
  global step,step_list,answer,m,visited,i_x,i_y
  d = [ [1,0],[0,1],[-1,0],[0,-1] ]
  if (start[0] == i_x )& (start[1] == i_y):
    step_list.append(step)
    step =0
    return step
  visited[start[0]][start[1]] = 1
  for i in range(4):
    next_step =(start[0]+d[i][0],start[1]+d[i][1])
    if (next_step[0] <0 | next_step[1] <0):
      continue
    if i== 3:
      if ((m[start[0]][start[1]-1]^m[start[0]-1][start[1]-1]) == 1)&(visited[next_step[0]][next_step[1]] == 0):
          step += 1
          search(next_step)
    elif i==1:
      if ((m[start[0]-1][start[1]]^m[start[0]][start[1]]) == 1)&(visited[next_step[0]][next_step[1]] == 0):
          step +=1
          search(next_step)
    elif i==2:
      if (((m[start[0]-1][start[1]])^(m[start[0]-1][start[1]-1]))== 1)&(visited[next_step[0]][next_step[1]] == 0):
          step += 1
          search(next_step)
    elif i==0:
      if (((m[start[0]][start[1]])^(m[start[0]][start[1]-1]))== 1)&(visited[next_step[0]][next_step[1]] == 0):
          step += 1
          search(next_step)
  return step

def solution(rectangle, characterX, characterY, itemX, itemY):
    global step,step_list,answer,m,visited,i_x,i_y
    answer = 0
    step = 0
    m= [[0 for col in range(100)] for row in range(100)]
    visited= [[0 for col in range(100)] for row in range(100)]
    step_list = []
    i_x =itemX
    i_y =itemY
    for r in rectangle:
      for i in range(r[0],r[2]):
        for j in range(r[1],r[3]):
          m[i][j]=1
    i_x,i_y = itemX, itemY
    search((characterX,characterY))
    answer = min(step_list)
    return answer