import sys
from math import *
from functools import cache
input = sys.stdin.readline



def solve():
    n, k = map(int, input().split())
    a = [*map(int, input().split())]
    pp = 55
    vis = [0] * 100
    for x in a:
        for p in range(pp, -1, -1):
            m = int(pow(k, p))
            if(x >= m):
                x -= m
                if vis[p] == 0:
                    vis[p] += 1
                else:
                    print("NO")
                    return
        if x:
            print("NO")
            return
    print("YES")

    
        
    





if __name__=="__main__":
    for _ in range(int(input())):
        solve()