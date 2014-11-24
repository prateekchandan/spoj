#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	vector<int> a(2665,0),b;
	for(int i=2;i<2665;i++)
	{
		if(a[i]==0)
		{
			for(int j=i+i;j<2665;j+=i)
			{
				a[j]++;
			}
		}
	}
	for(int i=2;i<2665;i++)
	{
		if(a[i]>=3)
		b.push_back(i);
	}
	int n,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<b[n-1]<<endl;
	}
	return 0;
}


