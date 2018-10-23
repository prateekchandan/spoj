#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int c,p;
    string s;
    map<string, int> mp;
    map<int, vector<string> > cp;
    for(int it = 1; it <= n; ++it)
    {
        cin>>c>>s;

        if(c!=3) cin>>p;

        switch(c)
        {
            case 1:
            case 2:
                if(mp.find(s) != mp.end())
                {
                    cp[mp[s]].erase(find(cp[mp[s]].begin(), cp[mp[s]].end(), s));
                    if(cp[mp[s]].size() == 0)
                    {
                        cp.erase(mp[s]);
                    }
                }
                mp[s] = p;
                cp[p].push_back(s);

                break;
            case 3:
            cout<<cp.begin()->second[0]<<" "<<it<<endl;
            s = cp.begin()->second[0];

            cp[mp[s]].erase(find(cp[mp[s]].begin(), cp[mp[s]].end(), s));
            if(cp[mp[s]].size() == 0)
            {
                cp.erase(mp[s]);
            }
      
            mp.erase(s);
        }

        //cout<<cp.size()<<" "<<mp.size()<<" *\n";
    }

}