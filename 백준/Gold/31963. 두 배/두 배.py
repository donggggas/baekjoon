from decimal import Decimal
from math import log2,ceil
n = int(input())
l = input().split()
r = 0
for i in range(n):l[i] = Decimal(str(log2(float(l[i]))))
for i in range(1,n):
    if l[i] >= l[i-1]:continue
    r += ceil(l[i-1]-l[i])
    l[i] += ceil(l[i-1]-l[i])
print(r)