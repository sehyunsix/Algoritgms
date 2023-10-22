


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

n=int(input())
for i in range(n):
  a,b =input().split()
  a = int(a)
  b = int(b)
  big = max(a,b)
  small = min(a,b)

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
  if gcd!= 1:
    print("IMPOSSIBLE")
  else:
    # result = np.array([[1,0],[0,1]])
    # if len(temp)>0:
    #   for t in temp[:-1]:
    #     result = np.array([[0 ,1],[1,-1*t[0]]])@result
    #   result= np.dot(np.array([1,-1*temp[-1][0]]),result)
    # else:
    #   result = a+1

    # print(result)
    if len(temp) > 0:
      result = [[1 ,0],[0,1]]
      for t in temp[:-1]:
          multiplication_matrix = [[0, 1], [1, -t[0]]]
          result = matrix_multiply(multiplication_matrix, result)

      last_temp = temp[-1]
      last_element = [[1, -last_temp[0]]]
      result = matrix_multiply(last_element, result)
      for row in result:
        print(abs(result[0][1]))

    else:
      print(a+1)
