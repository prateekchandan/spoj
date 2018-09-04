#include <bits/stdc++.h> 
using namespace std;

// Driver program to test above function
int main()
{
  int t,n,k,cnt;
  cin>>t;
  string txt,subst;
  while(t--)
  {
    cin>>n>>k;
    cin>>txt;
    set<string> stset;
    subst = txt.substr(0,k);
    stset.insert(subst);
    for (int i = 0; i <= n-k; ++i)
    {
      if(done[i] == 0)
      {
        KMPSearch(i,k, txt,done);
        cnt++;
      }
    }
    cout<<cnt<<endl;
  }
   return 0;
}