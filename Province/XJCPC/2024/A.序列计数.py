import sys,math
from math import *
from collections import *
from functools import cache
input=sys.stdin.readline
Mod = int(1e9+7)


def solve():
    n, m, k = map(int, input().split())
    k = min(k, m)
    def f(k):
        dp = [1] * k
        for i in range(n - 1):
            ndp = dp[:]
            for j in range(k):
                if j > 0:
                    ndp[j] += dp[j - 1]
                if j < k - 1:
                    ndp[j] += dp[j + 1]
                ndp[j] %= Mod
            dp = ndp
        return sum(dp) % Mod
    a, b = f(k), f(k - 1)
    b = a - b
    print((a + b * (m - k)) % Mod)





if __name__=="__main__":
    for _ in range(1):
        solve()