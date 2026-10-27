import sys
from math import *
from decimal import Decimal, getcontext
from collections import *
from functools import cache
getcontext().prec = 2000
input=sys.stdin.readline
MAXN = 10 ** 7
MOD = 998244353

dp = [0] * (MAXN + 1)
dp[0] = 1
a, b = 0, 1
while b <= MAXN:
    for i in range(MAXN - b, -1, -1):
        if not dp[i]: continue
        dp[i + b] = (dp[i + b] + b * dp[i]) % MOD
    a, b = b, a + b

def solve():
    n = int(input())
    print(dp[n])





if __name__=="__main__":
    for _ in range(int(input())):
        solve()