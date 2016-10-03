#include <bits/stdc++.h> 

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	int n,k,last,maxdiff,temp;
	cin>>t;

	while(t--)
	{
		cin>>n>>k;
		k+=2;
		vector<int> a(n);
		multiset<int> st;
		last = 0;
		maxdiff = -1;

		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			//cout<<i<<" & 1\n";
			if(st.size() == k)
			{
				st.erase(st.find(a[last++]));
			}
			st.insert(a[i]);
			temp = (*(--st.end())) - (*st.begin());
			if(temp > maxdiff)
				maxdiff = temp;
		}

		cout<<maxdiff<<endl;

	}	
	return 0;
}