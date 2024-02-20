n=int(input())
array = list(map(int, input().split()))


def bineary_search(num):
  global bucket
  start =0
  end =len(bucket)-1
  stack= [(start,end)]
  if ((bucket[-1]<num)) :
    bucket.append(num)
    return
  while stack:
    start,end= stack.pop()
    if start>=end:
      bucket[start] = num
      return
    mid= (start+end)//2
    if(num == bucket[mid]):
      return
    if (start  == mid):
      if bucket[mid]>=num:
        bucket[mid] = num
        return
      bucket[mid+1] = num
      return
    if(num > bucket[mid]):
      start = mid+1
      stack.append((start,end))
    elif(num < bucket[mid]):
      end = mid
      stack.append((start,end))



  def findPlace(e):
      start = 0
      end = len(LIS) - 1
      while start <= end:
          mid = (start + end) // 2
          if LIS[mid] == e:
              return mid
          elif LIS[mid] < e:
              start = mid + 1
          else:
              end = mid - 1
      return start

bucket= [array[0]]
for  a in array[1:]:
  bineary_search(a)
print(len(bucket))
