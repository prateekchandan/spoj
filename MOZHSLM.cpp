#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;

        int n = s.size();
        int pre[n], post[n];
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            pre[i] = cnt;
            if(s[i] == 's')
                cnt++;
        }
        cnt = 0;
        for(int i = n-1; i >=0; i--)
        {
            post[i] = cnt;
            if(s[i] == 's')
                cnt++;
        }
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            
            if(s[i] == 'm')
            {
                ans  += (long long) pre[i] * post[i]; 
            }
        }
        cout<<ans<<endl;
    }
}