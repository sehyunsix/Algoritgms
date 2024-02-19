import numpy as np
import math
import time



# start_time =time.time()
# print('start... test')
#  solution()
# end_time = time.time()
# print(f"Time taken: {end_time - start_time}")

grade=[3,2,3,6,4,5]

def solution(grade):
  answer =0
  for g,next in zip(grade[:-1],grade[1:]):
    if g > next:
      answer += g-next

  return answer


print(solution(grade))