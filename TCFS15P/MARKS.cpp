#include <bits/stdc++.h>
using namespace std;
int main(){
	int count[5]={0,0,0,0,0};
	vector<int> a[5];
	for (int i = 0; i < 5; i++)
	{
		vector<int> temp(101,0);
		a[i]=temp;
	}
	int n,m;
	char t;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>t>>m;
		t=t-'A';
		count[t]++;
		a[t][m]++;
	}
	for (int i = 0; i < 5; i++)
	{
		int op,flag=1;
		op=count[i]/10;
		
		for (int j = 0; j <= 100; j++)
		{
			if(a[i][j]>op){
				cout<<j<<" ";
				flag=0;
			}
		}
		if(flag)
		cout<<"Nothing Unusual";
		
		cout<<endl;	
		
	}
	
	return 0;
}
