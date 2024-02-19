n1 = int(input())
cards2 = list(map(int, input().split()))
n2 = int(input())
cards = list(map(int, input().split()))


cards_in_cards2 = [0]*n2

cards2.sort()

for i,c in enumerate(cards):
  stack=[(0, n1-1)]
  while stack:
    r= stack.pop()
    mid= (r[0]+r[1])//2
    if c == cards2[mid]:
      cards_in_cards2[i] = 1
      break
    if c>cards2[mid]:
      if cards2[r[1]]-c<0:
        break
      stack.append((mid+1, r[1]))
    else:
      if cards2[r[0]]-c>0:
        break
      stack.append((r[0],mid))
print(*cards_in_cards2)