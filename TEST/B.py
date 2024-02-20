

from collections import deque

# edgs = [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]
# n =6



def solution(n, edgs):
    level_list =[1]
    while level_list:
      if edgs:
        new_level_list =[]
        for e in level_list:
          for edge in edgs[:]:
            if ((e ==  edge[0])and(edge[1] not in level_list)) | ((e ==  edge[1])and(edge[0] not in level_list)):
              edgs.remove(edge)
              edge.remove(e)
              new_level_list.append(edge[-1])
        if new_level_list:
          level_list = list(set(new_level_list))
        else:
          break
      else:
        break
    return len(level_list)

print(solution(n,edgs))