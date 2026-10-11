import sys, math
from decimal import Decimal, getcontext
from collections import *
from functools import cache
getcontext().prec = 2000
sys.setrecursionlimit(5000)
MOD = int(1e9+7)
INF = int(1e18)
MAXX = int(2e5+10)
input = sys.stdin.buffer.readline



def solve() -> None:
    n = int(input())
    a = [*map(int, input().split())]
    a.sort()
    pre = a[0]
    g = 0
    for i in range(1, n):
        g = math.gcd(g, a[i] - a[i - 1])
    if g == 0:
        print('infinite')
    else:
        print(g, math.lcm(g, a[0]) // a[0])





if __name__=="__main__":
    for _ in range(int(input())):
        solve()