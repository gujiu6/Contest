import sys,math
from functools import cache
input=sys.stdin.readline



def solve():
    n = int(input())
    a = [*map(int, input().split())]
    b = [a[i + 1] - a[i] for i in range(len(a) - 1)]
    g = 0
    for i in range(1, len(b)):
        g = math.gcd(g, b[i] - b[0])
    print(-1 if g == 0 else g)





if __name__=="__main__":
    for _ in range(1):
        solve()