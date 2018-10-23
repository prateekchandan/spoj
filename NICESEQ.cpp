#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007

long long powMod(long long x,int n)
{
    if(n==0) return 1;
    if(n==1) return x % mod;

    long long temp = powMod(x, n/2);

    temp = (temp * temp) % mod;
    if(n%2 ==1) temp = (temp * x) % mod;

    return temp;
}

int main()
{
    int t;
    long long n, ans, temp;
    cin>>t;

    while(t--)
    {
        cin>>n;
        n--;
        if(n==0)
        {
            ans = 9;
        }
        else
        {
            ans = 1;
            ans += 5 * powMod(2, n) + powMod(3, n) + powMod(4, n) + powMod(5,n);
        }
        cout<<ans%mod<<endl;
    }
}