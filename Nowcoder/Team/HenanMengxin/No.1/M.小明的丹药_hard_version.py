import sys,math
from functools import cache
input=sys.stdin.readline



def solve():
    a, b, c, d = map(int, input().split())
    x = max(min(a, c) - 10, 0)
    y = max(min(b, d) - 10, 0)
    ans = x * 3 + y * 2
    a -= x
    b -= y
    c -= x
    d -= y
    add = 0
    for i in range(a + 1):
        for j in range(b + 1):
            u = i * 3 + j * 2
            for k in range(c + 1):
                m = u - k * 3
                if m % 2 or m > 2 * d:
                    continue
                add = max(add, u)
    print((ans + add) * 2)
    # print(add, ans)






if __name__=="__main__":
    for _ in range(int(input())):
        solve()