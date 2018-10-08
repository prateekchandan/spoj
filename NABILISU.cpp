#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int _it = 1; _it <= t; _it++)
    {
        int a,b,k;
        cin>>a>>b>>k;
        if(k==0 || (a != (b+k)))
        {
            cout<<"Case "<<_it<<": NO"<<endl;
        }
        else
        {
            cout<<"Case "<<_it<<": YES"<<endl;
        }
    }
}