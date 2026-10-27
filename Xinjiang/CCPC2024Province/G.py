from decimal import Decimal, getcontext
getcontext().prec = 2000
n = int(input())
a = []
for i in range(n):
    a.append(Decimal(input()))
s = str(sum(a))
if s != "0":
    s = str(sum(a)).rstrip('0').rstrip('.')
print(s)