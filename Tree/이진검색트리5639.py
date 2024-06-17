from sys import stdin
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

array = []
while True:
    try:
        x = int(input())
        array.append(x)
    except:
        break


def lowerbound(array, target):
    start, end = 0, len(array)
    while start < end:
        mid = (start + end) // 2
        if target <= array[mid]:
            end = mid
        else:
            start = mid + 1
    return start


def dfs(array):
    if len(array) == 0:
        return
    left = []
    right = []
    root = array[0]
    mid = 0
    for i in range(1, len(array)):
        if array[i] > root:
            mid = i
            left = array[1:mid]
            right = array[mid:]
            break
    else:
        left = array[1:]
    dfs(left)
    dfs(right)
    print(root)


dfs(array)
