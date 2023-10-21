n = int(input())
sequence= input().split()
sequence=list(map(int,sequence))
increase_count = 0
min =0
box_list = [0 for i in range(1001)]

for i in range(0,len(sequence)):
  box_list[sequence[i]] = max(box_list[:sequence[i]])+1

  # for j in range(sequence[i]-1,1000):
  #   if box_list[j]>0 :
  #     box_list[j] += 1

print(max(box_list))
