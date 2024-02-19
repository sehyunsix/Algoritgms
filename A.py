import numpy as np
import math
import time
# start_time =time.time()
# print('start... test')
#  solution()
# end_time = time.time()
# print(f"Time taken: {end_time - start_time}")

n=5
min_position=-5
max_position=3
positions =[-1,-3,3]
result =[-5,1]



def solution(n, min_position, max_position, positions):
  distance = max_position - min_position
  all_postions = [i for i in range(min_position,max_position+1,int(distance/(n-1)))]
  print(all_postions)
  for p in positions:
    all_postions.remove(p)
  all_postions.sort()
  return all_postions


print(solution(n, min_position, max_position, positions))