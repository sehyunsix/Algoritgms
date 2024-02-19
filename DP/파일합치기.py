
d = [[0]*1000 for _ in range(1000)]


#base[
# 1.누적합





# 2.최소합 d[i][j] = min(w[i][j]+ d[i][k] + d[k+1][j] for k in range(i,j)
# i,j range 설정 (까다롭다.) 기준은?


#i= 1만 있는 상태에서 -> i= 2로 넘어 갈 수이나?
# ==> 어떤 i 에서든지 j를 늘려가면서, i 부터 j까지 채울 수 있다?

# n= i - j = 2 일 경우
# d[i][j] = d[i][i+1]  => No need Reference

# n = i - j = 3일 경우
# d[i][j] = d[i][i+1]+ d[i+2][j]  => No need Reference
# d[i+2][j] = d[i+2][i+3]  => No need reference ->

# j= n +1
# i 1씩 증가시키기
# j n을 1 씩 증가시키기

# visualization
# array = [ 1,2,3,4,5]

#0 1 2 3 4 5
#0 0 0 0
#0 0 3 3
#0 0 0 5 5
#0 0 0 0 7 7


n = int(input())
for __ in range(n):
  num = int(input())
  array = list(map(int, input().split()))
  array = [0] + array
  prefix_sum = [0]*1001
  for i in  range(1,num+1):
      prefix_sum[i] = prefix_sum[i-1]+array[i]
  for n in range(1,num):
      for i  in range(1,num-n+1):
        j= i+n
        d[i][j] = min([prefix_sum[j]-prefix_sum[i-1]+ d[i][k] + d[k+1][j] for k in range(i,j) ])


  print(d[1][num])





