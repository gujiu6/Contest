import sys,math
from functools import cache
input=sys.stdin.readline



def solve():
    n = int(input())
    a = [*map(int, input().split())]
    k = 0
    ans = 0
    for x in a:
        if x > k:
            ans += x - k
        k = x
    print(ans)





if __name__=="__main__":
    for _ in range(1):
        solve()