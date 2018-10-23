#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

long long sumN(long long n)
{
    n = n % MOD;
    return ((n * (n+1))/2) % MOD;
}

long long calc(long long n, long long m)
{
    if(n==0) return 0;

    long long ans = sumN(n);
    long long x = n/m - 1; 
    long long temp = (sumN(x) + ((n%m) * (n/m))) % MOD;
    temp = (temp * (m%MOD))%MOD;

    return (ans-temp+MOD) % MOD;

}

int main()
{
    long long l,r,m;
    cin>>l>>r>>m;

    long long a,b;
    a = calc(l-1, m);
    b = calc(r, m);

    cout<<(b-a+MOD)%MOD;
}