#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	int n,W,totSum;
	while(t--)
	{
		cin>>n>>W;
		vector<int> w(n);
		totSum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>w[i];
			totSum+=w[i];
		}
		sort(w.begin(), w.end());
		for (int i = n-1; i>=0 ; --i)
		{
			if(totSum - w[i] >= W)
				totSum -= w[i];
		}
		cout<<totSum - W<<endl;
	}
	return 0;
}