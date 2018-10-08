#include <bits/stdc++.h>

using namespace std;

bool prime(long long x, vector<int> primes)
{
    for(int i = 0; i < primes.size(); ++i)
    {
        if(x%primes[i] == 0)
            return false;
    }
    return true;
}

int main()
{
    long long a,b;
    cin>>a>>b;

    int s = sqrt(b) + 2;
    int pr[s];

    for(int i=0; i < s; ++i) pr[i] = 0;
    pr[0] = pr[1] = 1;

    for(int i = 2; i < s; ++i)
    {
        if(pr[i] == 0)
        {
            for(int j = i+i; j < s; j+=i)
            {
                pr[j] = 1;
            }
        }
    }

    vector<int> primes;

    for(int i = 0; i < s; ++i)
    {
        if(pr[i] == 0)
        {
            primes.push_back(i);
        }
    }

    long long cost = 0;

    for(long long i = b; i > a; --i)
    {
        if(prime(i, primes))
        {
            cost+=i;
            break;
        }
        cost+=i;
    }
    cout<<cost<<endl;
}