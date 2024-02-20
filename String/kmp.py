
'''
KMP 알고리즘

패턴의 prefix 정보와 일치하는 가장 긴 suffix의 길이를 저장하는 배열을 사용해서 ,
문자열 검색을 O(N+M)으로 줄인 알고리즘.

특징: text를 pointer로 하는 index bactracking을 하지 않아도 된다


'''
str = input()
pattern = input()


def getpi(str):
  n = len(str)
  i=0
  pi = [0]*n
  for j in range(1,n):
    while i>0 and str[i] != str[j]:
      i= pi[i-1]
    if str[i] == str[j]:
      i +=1
      pi[j]=i
  return pi

pi = getpi(pattern)
n = len(str)

answer=[]

i=0
j=0

for i in range(0,len(str)):
  while j>0 and str[i] != pattern[j]:
      j= pi[j-1]
  if str[i] == pattern[j]:
    if j==len(pattern)-1:
      answer.append(i-len(pattern)+2)
      j=pi[j]
    else:
      j+=1

print(len(answer))
print(*answer)

