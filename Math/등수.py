import math
import time

COMB= [[ 1 for col in range(5001)] for row in range(5001)]
DP = [ 0 for x in range(5001)]
MOD = int(1e9)+7

def C(n,k):
  global COMB, MOD
  if COMB[n][k]>0 :
    return COMB[n][k]
  if ((k ==0) | (n ==k)):
    COMB[n][k]=1
    return 1
  COMB[n][k] = (C(n-1,k-1) +C(n-1,k))%MOD
  return COMB[n][k]

def make_CB():
  for n in range(2,5001):
      for k in range(1,n):
       COMB[n][k] = (COMB[n-1][k-1] + COMB[n-1][k])%MOD


def make_DP():
  global DP , MOD
  DP[0] =1
  DP[1] =1
  for i in range(2,5001):
    temp =1
    for j in range(1,int(i/2)+1):
      t=COMB[i][j] =COMB[i][i-j]= (COMB[i-1][j-1] + COMB[i-1][j])%MOD
      temp += t*(DP[j]+ DP[i-j])
    if (i%2 ==0):
      temp -= (COMB[i][int(i/2)]*DP[int(i/2)])
    DP[i] = temp%MOD
    # print(f"DP[{i}]={DP[i]}")
  return True


if __name__ =='__main__':
  # start_time =time.time()
  # print('start... test')
  #  make_CB()
  # end_time = time.time()
  # print(f"Time taken: {end_time - start_time}")
  # start_time =time.time()
  # print('start... make_DP')
  make_DP()
  # end_time = time.time()
  # print(f"Time taken: {end_time - start_time}")
  # print(f"메모리사이즈 COMB:{sys.getsizeof(COMB)}")
  # print(f"메모리사이즈 DP:{sys.getsizeof(DP)}")
  # end_time = time.time()
  # print(f"Time taken: {end_time - start_time}")
  case = int(input())
  for __ in range(case):
      n, k = list(map(int,input().split(" ")))
      answer =0
      if k == n:
        answer = DP[k-1]*DP[n-k]*COMB[n-1][k-1]
      else:
        answer = DP[k-1]*DP[n-k]*COMB[n-1][k-1]*2
      print(answer%MOD)