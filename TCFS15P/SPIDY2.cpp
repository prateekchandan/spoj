#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long h[n];
	for (int i = 0; i < n; i++)
	{
		cin>>h[i];
	}
	vector<long long> cost(n,0);
	for (int i = n-2; i >= 0 ; i--)
	{
		long long minc=INT_MAX,c;
		for (int j = 1; i+j < n; j*=2)
		{
			c=cost[i+j]+abs(h[i+j]-h[i]);
			if(c<minc)
				minc=c;
		}
		cost[i]=minc;
	}
	cout<<cost[0];
	
	return 0;
}

