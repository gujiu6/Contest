import sys,math,heapq
from functools import cache
input=sys.stdin.readline



def solve():

    S = input().strip()
    o, z = S.count('1'), S.count('0')
    ones = []
    zero = []
    f = o % 2 == 0
    k = 0
    o -= f
    z += f
    for i in range(1, o + 1):
        ones.append((1 << 32) + i)
        k ^= (1 << 32) + i
    for i in range(1, z + 1):
        zero.append(i)
        k ^= i

    for ch in S:
        if ch == '1':
            if f:
                f = 0
                print(zero.pop(), end=' ')
            else:
                print(ones.pop(), end=' ')
        else:
            print(zero.pop(), end=' ')
    print()



if __name__=="__main__":
    for _ in range(1):
        solve()