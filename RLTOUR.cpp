#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
bool mysort(int a,int b)
{
	return a>b;
}
int main(){
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int> a(n);
		vector<int> b(n);
		int res[n];
		for (int i = 0; i < n; i++)
		{
			cin>>a[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin>>b[i];
		}
		sort(a.begin(),a.end(),mysort);
		
		for (int i = n-1; i >= 0; i--)
		{
			res[i]=a.at(b[i]);
			a.erase(a.begin()+b[i]);
		}
		for (int i = 0; i < n; i++)
		{
			cout<<res[i]<<" ";
		}
		cout<<endl;
		
	}
	return 0;
}

