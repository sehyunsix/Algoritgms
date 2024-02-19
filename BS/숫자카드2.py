from collections  import Counter
# card_t
# card

n = int(input())
card_t = list(map(int, input().split()))
n2 = int(input())
card = list(map(int, input().split()))

card_t = Counter(card_t)
for i in card:
  print(card_t[i], end=' ')