// PRATEEK CHANDAN
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

int main()
{
	int n,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n],ma[n],mi[n];
		for (int i = 0; i < n; i++)
		{
			cin>>a[i];
			ma[i]=0;
			mi[i]=0;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i-1; j >=0 ; j--)
			{
				if(a[j]<a[i]){
					if(mi[j]+1 > mi[i])
						mi[i]=mi[j]+1;
				}
			}
			
		}
		
		for (int i = n-1; i >= 0; i--)
		{
			for (int j = i+1; j <n ; j++)
			{
				if(a[j]<a[i]){
					if(ma[j]+1 > ma[i])
						ma[i]=ma[j]+1;
				}
			}
			
		}
		int maxi=0;
		for (int i = 0; i < n; i++)
		{
			//cout<<ma[i]<<":"<<mi[i]<<"  ";
			if((ma[i]+mi[i]+1)>maxi)
			maxi=ma[i]+mi[i]+1;
		}
		cout<<maxi<<endl;
	}
	
	return 0;
}

