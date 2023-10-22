import numpy as np

a ='abcdefasdfadfasdff'
b ='gbcdfeasdfasdfasdfsad'

lcs_table=np.zeros((len(a)+1,len(b)+1),dtype= np.int32)
b_table = np.zeros((len(a)+1,len(b)+1),dtype= np.int32)


for i in range(1,len(a)+1):
  for j in range(1,len(b)+1):
    if a[i-1] == b[j-1]:
      lcs_table[i][j] = lcs_table[i-1][j-1]+1
      b_table[i][j] = 3
    else:
      lcs_table[i][j] = max(lcs_table[i-1][j],lcs_table[i][j-1])
      if lcs_table[i][j] ==lcs_table[i-1][j]:
        b_table[i][j] = 2
      else:
        b_table[i][j] = 1

result =[]

def find_lcs(i,j,):
  if i*j == 0:
    return
  if b_table[i][j] == 3:
    result.append(a[i-1])
    find_lcs(i-1,j-1)
  elif b_table[i][j] == 2:
    find_lcs(i-1,j)
  elif b_table[i][j] == 1:
    find_lcs(i,j-1)

print(lcs_table)
print(b_table)
find_lcs(15,15)
print(result)
result.reverse()
print(result)
