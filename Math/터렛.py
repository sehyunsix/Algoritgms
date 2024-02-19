import math
n = int(input())
for __ in range(n):
  str = input()
  x1,y1,r1,x2,y2,r2 = list(map(int,str.split(" ")))

  #check circle in other circle
  def check_include(b_c ,s_c):
    b_x, b_y, b_r = b_c
    s_x, s_y, s_r = s_c
    if((math.sqrt(pow(b_x-s_x,2)+pow(b_y-s_y,2))+s_r) < b_r):
        return 1

    elif((math.sqrt(pow(b_x-s_x,2)+pow(b_y-s_y,2))+s_r) == b_r):
        return 2
    else:
        return 0

  if (r1>r2):
    check_in = check_include((x1,y1,r1),(x2,y2,r2))
  else:
    check_in = check_include((x2,y2,r2),(x1,y1,r1))


  r_d = pow(r1+r2,2)
  m_d = pow(x1-x2,2)+pow(y1-y2,2)

  if(x1==x2 and y1==y2 and r1==r2):
        print(-1)

  elif check_in:
    if check_in == 2:
        print(1)
    else:
        print(0)

  else:
    if(x1==x2 and y1==y2 and r1!=r2):
        print(0)
    elif(m_d ==r_d):
        print(1)
    elif(m_d >r_d):
        print(0)
    elif(m_d <r_d):
        print(2)
    else:
        print(-1)