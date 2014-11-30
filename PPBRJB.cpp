#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int ans[41];
	ans[0]=1;
	ans[1]=1;
	ans[2]=1;
	ans[3]=1;
	for (int i = 4; i < 41; ++i)
	{
		ans[i]=ans[i-1]+ans[i-4];
	}
	int ans40=217287;
	vector<int> pr(ans40,1);
	pr[0]=0; pr[1]=0;
	for (int i = 2; i < ans40; ++i)
	{
		if(pr[i]){
			for (int j = i+i; j < ans40; j+=i)
			{
				pr[j]=0;
			}
		}
	}
	vector<int> cum(ans40,0);
	for (int i = 1; i < ans40; ++i)
	{
		cum[i]=cum[i-1];
		if(pr[i]){
			cum[i]++;
		}
	}

	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<cum[ans[n]]<<endl;
	}
	return 0;
}