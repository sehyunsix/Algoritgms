
test = [11,10,9,8,7,6,5,4,3,2,1]

def Merge_sort(data):
  if len(data) == 1 :
    return data
  else :
    mid =len(data)//2
    left=Merge_sort(data[0:mid])
    right=Merge_sort(data[mid:])
    print("left :",left)
    print("right :",right)
    result =[]
    leftnumber = 0
    rightnumber = 0
    for i in range(len(data)):
      if leftnumber>=len(left):
        result.append(right[rightnumber])
        rightnumber +=1
      elif rightnumber >= len(right):
        result.append(left[leftnumber])
        leftnumber +=1
      elif left[leftnumber]< right[rightnumber]:
        result.append(left[leftnumber])
        leftnumber += 1
      else:
        result.append(right[rightnumber])
        rightnumber += 1
    return result

sorted =Merge_sort(test)
print(sorted)
