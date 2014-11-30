#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <tr1/unordered_map>
using namespace std;
int county;

void merge(vector<int> a,int st,int en,int i1,int j1,vector<int> &n){
	
	for (int i = st; i <= j1; i++)
	{
		if(st>en)
		{
			n[i]=a[i1];
			i1++;
			county+=en-st+1;
			
		}
		else if(i1>j1)
		{
			n[i]=a[st];
			st++;
		}
		else if(a[st]<a[i1])
		{
			n[i]=a[st];
			st++;
		}
		else{
			n[i]=a[i1];
			i1++;
			county+=en-st+1;
			
		}
	}
	
}
void mergesort(vector<int> &n,int st,int en){
	
	if(st >= en)
		return;
		
	int mid=(st+en)/2;
	mergesort(n,st,mid);
	mergesort(n,mid+1,en);
	merge(n,st,mid,mid+1,en,n);
	
	/*cout<<"\n************************\n";
		cout<<st<<":"<<mid<<":"<<en<<" & "<<county<<endl;
		for (int i = st; i <= mid; i++)
		{
			cout<<n[i]<<" ";
		}
		cout<<endl;
		for (int i = mid+1; i <= en; i++)
		{
			cout<<n[i]<<" ";
		}
		
		cout<<endl;
		for (int i = st; i <= en; i++)
		{
			cout<<n[i]<<" ";
		}
		
	cout<<"\n************************\n";*/
	
	
}
int main(){
	int t,n;
	string a;
	cin>>t;
	while (t--)
	{
		county=0;
		cin>>n;
		
		tr1::unordered_map<string,int> x;
		vector<int> z(n);
		
		for (int i = 0; i < n; i++)
		{
			cin>>a;
			x[a]=i;
		}
		
		for (int i = 0; i < n; i++)
		{
			cin>>a;
			z[i]=x[a];
			//cout<<z[i]<<" : "  ;
		}	
		//cout<<endl;
		
		mergesort(z,0,n-1);
		
		cout<<county<<endl;
	}
	
	return 0;
}

