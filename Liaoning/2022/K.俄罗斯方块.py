import sys,math
from functools import cache
input=sys.stdin.readline

#8
a = [[1], [1, 1], [1, 2, 2], [3, 2, 2, 4], [3, 3, 4, 4, 4], [3, 5, 5, 5, 6, 6], [7, 7, 5, 8, 6, 6, 9], [7, 7, 8, 8, 8, 9, 9, 9]]
#7
b = [[1], [1, 1], [1, 2, 2], [3, 2, 2, 4], [3, 3, 4, 4, 4], [3, 5, 6, 6, 6, 7], [5, 5, 5, 6, 7, 7, 7]]

def solve():
    n = int(input())
    m = (1 + n) * n // 2
    if m % 4 != 0:
        print("NO")
        return
    if n % 8 == 0 or n % 8 == 7:
        print("YES")
    else:
        print("NO")
        return
    total = m // 4
    if n % 8 == 0:
        for i in range(8):
            for j in range(i + 1):
                print(a[i][j], end = ' ')
            print()
        st = 9
        ed = 16
        id = 10
        num = (st - 1) // 2
        idx = num * 4 + id - 1
        while ed <= n:
            for i in range(st, ed + 1):
                for j in range(i):
                    if j < num * 2:
                        print(id + j // 2, end = ' ')
                    else:
                        print(idx + a[i - st][j - num * 2], end = ' ')
                if (i - st) % 2:
                    id += num
                print()
            id = (1 + ed) * ed // 2 // 4 + 1
            st += 8
            ed += 8
            num = (st - 1) // 2
            idx = num * 4 + id - 1
    else:
        for i in range(7):
            for j in range(i + 1):
                print(b[i][j], end = ' ')
            print()
        st = 8
        ed = 15
        id = 8
        num = st // 2
        idx = num * 4 + id - 1
        while ed <= n:
            for i in range(st, ed + 1):
                for j in range(i):
                    if j < num * 2:
                        print(id + j // 2, end = ' ')
                    elif i != st:
                        print(idx + b[i - st - 1][j - num * 2], end = ' ')
                if (i - st) % 2:
                    id += num
                print()
            id = (1 + ed) * ed // 2 // 4 + 1
            st += 8
            ed += 8
            num = st // 2
            idx = num * 4 + id - 1
    # print(m // 4)    
    

    





if __name__=="__main__":
    for _ in range(1):
        solve()