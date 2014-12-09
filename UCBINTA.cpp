#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int total=100001;
int main(int argc, char const *argv[])
{
	int n;
	int temp;
	cin>>n;
	long long totsum=0;
	vector<long long> rowsum(n,0);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>temp;
			totsum+=temp;
			rowsum[i]+=temp;
		}
	}
	totsum/=(2*n-2);
	for (int i = 0; i < n; ++i)
	{
		if(n==2)
			cout<<rowsum[i]/2<<" ";
		else
			cout<<(rowsum[i]-totsum)/(n-2)<<" ";
	}
	return 0;
}