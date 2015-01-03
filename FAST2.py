mod = 1298074214633706835075030044377087

t = input()

def pow(n):
	if n==0:
		return 1
	else:
		return 2*pow(n-1)


i = 0

ans = []
temp = 1
while i<505:
	temp = temp*2
	a = temp - 1
	if temp > mod:
		temp = temp % mod
	if a>mod:
		a = a % mod
	ans.append(a)
	i=i+1

i =0
while i<t:
	n = input()
	print ans[n]
	i=i+1