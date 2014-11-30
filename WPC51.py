def gcd(a,b):
    if a%b==0:
        return b
    else:
        return gcd(b,a%b)
t=int(input())
while t>0:
    t=t-1
    a,b=input().split()
    a=int(a)
    b=int(b)
    c=gcd(a,b)
    print(int(((a*b)/c)/c))
