
import numpy as np
import math

maps = np.array([[0,0,0,0,0],[0,1,1,1,0],[0,0,1,0,0],[0,0,1,1,2],[0,0,0,0,0]])
visited = np.zeros(maps.shape,dtype=np.int32)

#requrence
def dfs(start):
  global visited, maps
  d = [[1,0],[0,1],[-1,0],[0,-1]]
  visited[start[0]][start[1]]=1
  if (maps[start[0]][start[1]]==2):
    print('find!')
    return 2
  nexts  = [[start[0]+i[0],start[1]+i[1]] for i in d]
  for next in nexts:
    if (next[0]>=0 and next[0]<maps.shape[0]) and (next[1]>=0 and next[1]<maps.shape[1]) and (visited[next[0]][next[1]]==0) and (maps[next[0]][next[1]] != 0):
      print(next)
      return dfs(next)
  return 0

print(maps)
print(dfs([1,1]))
print(visited)
