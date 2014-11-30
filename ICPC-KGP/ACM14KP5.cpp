#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <limits.h>
using namespace std;
int main(){
	int t,n,temp;
	cin>>t;
	for(int iter=1;iter<=t;iter++){
		cin>>n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin>>a[i];
		}
		int maxval=INT_MIN;
		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				for (int k = j+1; k < n; k++)
				{
					temp=a[i]+a[j]+a[k];
					if(temp>maxval)
						maxval=temp;
				}
				
			}
			
		}
		
		cout<<"Case "<<iter<<":"<<" "<<maxval<<endl;;
	}
	return 0;
}
