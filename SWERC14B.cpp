#include <iostream>
#include <cstdio>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
int main()
{
	int p,t,a,b,cost;
	cin>>p>>t;
	vector<vector<pair<int,int> > > tracks(p);
	vector<int> minp(p,INT_MAX);
	for (int i = 0; i < t; ++i)
	{
		cin>>a>>b>>cost;
		tracks[a].push_back(pair<int,int>(b,cost));
		tracks[b].push_back(pair<int,int>(a,cost));
	}

	vector<pair<int,int> > minh;
	for (int i = 0; i < tracks[0].size(); ++i)
	{
		
	}

	return 0;
}