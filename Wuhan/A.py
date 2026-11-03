import sys, math
from decimal import Decimal, getcontext
from collections import *
from functools import cache
getcontext().prec = 2000
sys.setrecursionlimit(5000)
MOD = int(1e9+7)
INF = int(1e18)
MAXX = int(2e5+10)
# input = sys.stdin.buffer.readline



def solve() -> None:
    n = int(input())
    p = 0
    ans = 1
    for _ in range(n):
        s = input()
        if s == "zaoshanghao":
            p = 1
        elif s == "yeshenle" and p:
            ans += 1
            p = 0
    print(ans)
        





if __name__=="__main__":
    # for _ in range(int(input())):
        solve()