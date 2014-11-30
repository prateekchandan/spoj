#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
	int t,n;
	int max1,temp;
	cin>>t;
	for (int i = 0; i < t; i++)
	{
		max1=0;
		cin>>n;
		for (int j = 0; j < n; j++)
		{
			cin>>temp;
			if(temp>max1)
			max1=temp;
		}
		cout<<max1<<"\n";
	}
	
}
