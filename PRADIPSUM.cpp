#include <iostream>

using namespace std;

int main()
{
    long long a,b,sum, s1, s2;
    while(cin>>a)
    {
        cin>>b;
        if(b<a)
        {
            a = a+b;
            b = a-b;
            a = a-b;
        }

        s1 = (abs(a) * (abs(a)+1))/2;
        s2 = (abs(b) * (abs(b)+1))/2;

        if(a>=0 && b>=0)
        {
            cout << s2 - s1 + a;
        }
        else if(a < 0 && b < 0)
        {
            cout << -1 * (s1 - s2) + b;
        }
        else
        {
            cout<<s2 - s1;
        }
        cout<<endl;
    }
}

