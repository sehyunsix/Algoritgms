def quick_sort(data):
  if len(data) <= 1:
    return data
  pivot = data[0]
  left = [item for item in data[1:] if item <= pivot]
  right = [item for item in data[1:] if item > pivot]
  return quick_sort(left) + [pivot] + quick_sort(right)

print(quick_sort([11,10,9,8,7,6,5,4,3,2,1]))