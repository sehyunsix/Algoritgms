


def matrix_multiply(a, b):
    # 행렬 a와 b의 곱셈을 수행
    rows_a = len(a)
    cols_a = len(a[0])
    rows_b = len(b)
    cols_b = len(b[0])

    # 결과 행렬 초기화
    result = [[0 for _ in range(cols_b)] for _ in range(rows_a)]

    # 행렬 곱셈 수행
    for i in range(rows_a):
        for j in range(cols_b):
            for k in range(cols_a):
                result[i][j] += a[i][k] * b[k][j]

    return result

number_list =[]
n=int(input())
for i in range(n):
  a,b =input().split()
  a = int(a)
  b = int(b)
  number_list.append((a,b))

for numbers in number_list:
  a = numbers[0]
  b= numbers[1]
  if a > b:
    big,small= a,b
  else:
    big,small = b,a

  temp = []
  ## 서로수 찾기
  def find_gcd(big,small):
    if(big % small == 0):
      return small
    else:
      temp.append((big//small,big%small))
      return find_gcd(small, big%small)
  ## 정수조합찾기

  gcd = find_gcd(big,small)
  if gcd != 1:
    print("IMPOSSIBLE")
  else:
    if len(temp) > 0:
      result = [[1 ,0],[0,1]]
      for t in temp[:-1]:
          multiplication_matrix = [[0, 1], [1, -t[0]]]
          result = matrix_multiply(multiplication_matrix, result)

      last_temp = temp[-1]
      last_element = [[1, -last_temp[0]]]
      result = matrix_multiply(last_element, result)
      for row in result:
        if big == b:
          if result[0][0] <0:
            # print(result[0][0]+a)
            final = result[0][0]+a
          else:
            # print(result[0][0])
            final = result[0][0]
        else:
          if result[0][1] <0:
            # print(result[0][1]+a)
            final = result[0][1]+a
          else:
            # print(result[0][1])
            final = result[0][1]

    else:
      final = a+1

    if final >pow(10,9):
      print("IMPOSSIBLE")
    else:
      print(final)
