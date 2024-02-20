n= int(input())
array = list(map(int, input().split()))

lis = [0]*n
for i in range(0,n):
  lis[i] =1
  for  j in range(0,i):
    if (array[j]<array[i]) and (lis[i]<lis[j]+1):
      lis[i] = lis[j]+1
print(max(lis))

