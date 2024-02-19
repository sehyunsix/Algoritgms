## 문제정의
# weight 와 있는 value가 주어진 item을
# capicity가 있는 가방에 넣을 수 있는 아이템들의 value들의 최댓값은?

import numpy as np

item =[[1,1],[6,2],[18,5],[22,6],[28,7]]

W = 11
item.insert(0,[0,0])
optimal_W_table = np.zeros((len(item)+1,W+1))
print(item[5])
for i in range(1, len(item)):
  for j in range(1, W+1):
    if item[i][1] >j:
      optimal_W_table[i][j] = optimal_W_table[i-1][j]
    else:
      optimal_W_table[i][j] = max(optimal_W_table[i-1][j],
                                  item[i][0]+optimal_W_table[i-1][j-item[i][1]])
print(optimal_W_table)
