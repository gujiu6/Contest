import sys,math
from functools import cache
input=sys.stdin.readline



def solve():
    n = int(input())
    ans = ""
    if n >= -127 and n <= 128:
        ans = "byte"
    elif n >= -32768 and n <= 32767:
        ans = "short"
    elif n >= -2147483648 and n <= 2147483647:
        ans = "int"
    elif n >= -9223372036854775808 and n <= 9223372036854775807:
        ans = "long"
    else:
        ans = "BigInteger"
    print(ans)





if __name__=="__main__":
    for _ in range(1):
        solve()