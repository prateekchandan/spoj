#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int t,n;
	cin>>t;
	for (int no = 0; no < t; ++no)
	{
		cin>>n;
		if(n==0){
			cout<<"Case "<<no+1<<": 0\n";
			continue;
		}

		vector<long long> coins(n),ans(n,0);
		for (int i = 0; i < n; ++i)
		{
			cin>>coins[i];
		}
		if(n==1){
			cout<<"Case "<<no+1<<": "<<coins[0]<<"\n";
			continue;
		}

		ans[0]=coins[0];
		ans[1]=(coins[0]>coins[1]?coins[0]:coins[1]);
		for (int i = 2; i < n; ++i)
		{
			ans[i]=max(ans[i-1],ans[i-2]+coins[i]);
		}
		cout<<"Case "<<no+1<<": "<<ans[n-1]<<"\n";
	}
	return 0;
}