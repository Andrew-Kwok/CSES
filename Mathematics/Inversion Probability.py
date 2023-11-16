from decimal import *
import math
 
getcontext().prec = 30
 
n = int(input())
v = list(map(Decimal, input().split()))
 
res = Decimal(0)
for i in range(n):
	for j in range(i+1, n):
		if v[i] <= v[j]:
			res += v[i] * (v[i]-1) / 2 / (v[i] * v[j])
		else:
			res += (v[j] * (v[j]-1) / 2 + (v[i] - v[j]) * v[j]) / (v[i] * v[j]);
 
print("{:.6f}".format(round(res, 6)));
