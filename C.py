import math
import time



# start_time =time.time()
# print('start... test')
#  solution()
# end_time = time.time()
# print(f"Time taken: {end_time - start_time}")


#case1
data = ["1 GRAY 0", "2 MUSSEUK 0", "3 DOLL 1", "4 DOLL 2", "5 LARGE-GRAY 3", "6 SMALL-GRAY 3", "7 WHITE-MUSSEUK 4", "8 GRAY-MUSSEUK 4"]
word ="GRAY"

#case2
# data = ["1 GRAY 0", "2 MUSSEUK 0", "3 DOLL 1", "4 DOLL 2", "5 LARGE-GRAY 3", "6 SMALL-GRAY 3", "7 WHITE-MUSSEUK 4", "8 GRAY-MUSSEUK 4"]
# word ="KITTY"

# #case3
# data = ["1 ROOTA 0", "2 AA 1", "3 ZZZ 1", "4 AABAA 1", "5 AAAAA 1", "6 AAAA 1", "7 BAAAAAAA 1", "8 BBAA 1", "9 CAA 1", "10 ROOTB 0", "11 AA 10"]
# word = "AA"

class Node:
  def __init__(self, information ):
    self.ID =information[0]
    self.name = information[1]
    self.parent = information[2]
    self.child =[]

  def _print(self):
    print(self.name)

def dfs(start,search):
  stack = [(start,'')]
  leaf_nodes =[]
  while stack:
    node = stack.pop()
    if (not node[0].child) &( search in node[0].name):
      key =[ 0,0,0,0,0]
      if search == node[0].name:
        key[0] = 1
      word_stack =[0]
      word_index_list=[]
      word_count =0
      while word_stack:
        start =word_stack.pop()
        index = node[0].name.find(search,start)
        if index>-1:
          word_stack.append(index+len(search))
          word_count +=1
          word_index_list.append(5000 -index)
      key[1] = word_count
      key[2] = word_index_list
      key[3] = 5000 - int(node[0].ID)
      key[4] = node[0].name
      leaf_nodes.append((node[1]+node[0].name, node[0], key))
    if len(node[0].child) >0:
      for c in node[0].child:
        stack.append((c,node[1]+node[0].name+'/'))

  return leaf_nodes


def solution(data, word):
  data = [Node(d.split(" ")) for d in data]
  root_list =[data for data in data if data.parent == '0']
  for r in root_list:
    data.remove(r)

  #make root tree
  for r in root_list:
    stack =[r]
    while stack:
      node = stack.pop()
      for d in data:
        if d.parent == node.ID:
          d.parent = node
          node.child.append(d)
          stack.append(d)
      if node.child:
        for c in node.child:
          data.remove(c)

  # make result
  search_result = []
  for r in root_list:
    search_result.extend(dfs(r,word))

  if len(search_result) ==0:
    answer = [f"Your search for ({word}) didn't return any results"]
    return answer
  else:
    search_result.sort(key=lambda x: (x[2][0],x[2][1],x[2][2],x[2][3]) ,reverse=True)
  answer = [ s[0] for s in search_result]
  print(answer)
  return answer



solution(data, word)





