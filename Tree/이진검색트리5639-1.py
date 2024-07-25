stdin = [50, 30, 24, 5, 28, 45, 98, 52, 60]
stack = []


def lowerbound(array, target):
    start, end = 0, len(array)
    while start < end:
        mid = (start + end) // 2
        if target >= array[mid]:
            end = mid
        else:
            start = mid + 1
    return start


print(lowerbound([50, 30, 24, 5], 28))

for line in stdin:
    if len(stack) == 0:
        stack.append(int(line))
    else:
        if stack[-1] > int(line):
            stack.append(int(line))
        else:
            temp = int(line)
            while stack[-1] < temp:
              print(stack.pop())
            mid = lowerbound(stack, temp)
            cut = stack[mid:]
            root = cut[0]
            cut = cut[1:]
            stack = stack[:mid]
            for c in cut:
                print(c)
