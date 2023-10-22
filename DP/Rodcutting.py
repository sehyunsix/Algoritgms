## 문제정의
# 통나무를 어떤 족각들로 잘라야 가장 큰 이득을 보는가

value =[1,5,8,9,10,17,17,20,24,30]
rod_len = 50
rod_table =[ 0 for x in range(51)]

for i in range(1,51):

  rod_table[i] = max([rod_table[i-x-1] + value[x] for x in range(min(i,10))] )

print(rod_table)