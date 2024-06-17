from collections import deque


n = N


def divide(a, b):
    return a // b


def plus_one(a, b):
    return a + 1


def plus_two(a, b):
    return a + (2 * n)


def plus(a, b):
    return a + b


def minus(a, b):
    return a - b


def multiply(a, b):
    return a * b


def concate(a, b):
    return int(str(a) + str(b))


func_list = [divide, plus, minus, multiply, concate]
two_list = [plus_two, plus_one]
success = False
answer = -1
deq = deque([(n, 1)])
while (deq is not None) & (success == False):
    start, count = deq.popleft()
    # print("deq:", deq)
    if count > 8:
        break
    for f in func_list:
        # print("f start:", start, f(start, n), count)
        if f(start, n) == number:
            success = True
            answer = count + 1
            break
        deq.append((f(start, n), count + 1))
    if success == False:
        for t in two_list:
            # print("start:", start, t(start, n), count)
            if t(start, n) == number:
                if answer > count + 2:
                    success = True
                    answer = count + 2
                    break
            deq.append((t(start, n), count + 2))

print(answer)

# for f in func_list:
#     print(f(n, n))
