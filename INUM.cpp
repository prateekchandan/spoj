#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	vector<long long> a;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	long long mindif=a[1]-a[0],maxdif=a[n-1]-a[0],temp;
	
	for (int i = 1; i < n; ++i)
	{
		temp=a[i]-a[i-1];
		if (temp<mindif)
			mindif=temp;
	}

	int minc,maxc;
	

	return 0;
}