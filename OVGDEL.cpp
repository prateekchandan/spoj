#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    int m = 1000001;

    cin>>t;

    for(int _it = 1; _it <=t; ++_it)
    {
        int n;
        cin>>n;
        vector<int> fre(m,0),a(n);

        for(int i = 0; i < n; ++i)
        {
            cin>>a[i];
            fre[a[i]]++;
        }

        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            for(long long j = 1; j < m; j*=a[i])
            {
                if(j == a[i])
                {
                    if(fre[j] > 1)
                    {
                        ans++;
                        break;
                    }
                }
                else if(fre[j] > 0)
                {
                    ans++;
                    break;
                }
                if(a[i] == 1)
                break;
            }
        }

        cout<<"Case "<<_it<<": "<<ans<<endl;

    }
}