


def bubble_sort(data):
  for i in range(len(data)):
    for j in range(len(data)-1):
      if data[j] > data[j+1]:
        data[j], data[j+1] = data[j+1], data[j]
  return data

print(bubble_sort([11,10,9,8,7,6,5,4,3,2,1]))