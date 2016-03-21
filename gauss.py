import math

n = eval(raw_input())
a = [[]]
b = []
x = [0.0 for i in range(n+1)]
for i in range(n):
	a.append([0.0] + [float(eval(i)) for i in raw_input().split()])
print 'A =', a

b = [0.0] + [float(eval(i)) for i in raw_input().split()]
print 'B =', b

for k in range(1, n):
	p = k
	for j in range(k+1, n+1):
		if (abs(a[j][k]) > abs(a[p][k])):
			p = j
	if a[p][k] == 0:
		print 'Singular!'
		break
	if p != k:
		t = a[p]; a[p] = a[k]; a[k] = t
	for i in range(k+1, n+1):
		m = a[i][k] / a[k][k]
		b[i] -= b[k]*m
		for j in range(k+1, n+1):
			a[i][j] -= a[k][j]*m

if a[n][n] == 0:
	print 'Singular!'
else:
	x[n] = b[n] / a[n][n]
	for k in range(n-1, 0, -1):
		x[k] = (b[k] - sum([a[k][j]*x[j] for j in range(k+1, n+1)])) / a[k][k]

print 'x =', x

print 'Validation:'
print [sum([a[i][j]*x[j] for j in range(1, n+1)]) for i in range(1, n+1)]