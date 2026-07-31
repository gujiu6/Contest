import sys,math
from math import *
from collections import *
from functools import cache
input=sys.stdin.readline



def solve():
    n = int(input())
    arr = [0] * 3000
    idx = 1500
    while n > 0:
        x = input().strip()
        a, b = x, ""
        if '.' in x:
            a, b = x.split('.')
        a = a[::-1]
        for i, cur in enumerate(a):
            arr[idx - i] += int(cur)
        for i, cur in enumerate(b):
            arr[idx + i + 1] += int(cur)
        n -= 1
    l = len(arr)
    for i in range(l - 1, 0, -1):
        j = i - 1
        if j >= 0:
            arr[j] += arr[i] // 10
            arr[i] %= 10
    start = 0
    while start < idx and arr[start] == 0:
        start += 1
    end = len(arr) - 1
    while end > idx and arr[end] == 0:
        end -= 1
    st = "".join(map(str, arr[start : idx + 1]))
    if end > idx:
        ed = "." + "".join(map(str, arr[idx + 1 : end + 1]))
    else:
        ed = ""

    print(st + ed)
    
    
            

        






if __name__=="__main__":
    for _ in range(1):
        solve()