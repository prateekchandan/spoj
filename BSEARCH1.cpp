#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int st,en,mid;

void bsearch(int a[],int &n,int &val){
	if(val < a[0] && val > a[n-1]){
		cout<<"-1\n";
		return ;
	}
		
	st=0;en=n-1;
	while(st <= en)
	{
		mid=(st+en)>>1;
		if(a[mid]==val){
			bool flag=false;
			while(a[mid]==val && mid>=0){
				mid--;
				flag=true;
			}
			if (flag)
				cout << mid + 1<<"\n";
			else
				cout << mid <<"\n";
			return ;
		}
		else if(a[mid]>val)
			en = mid-1;
		else
			st=mid+1;
	}
	cout<<"-1\n";
	return ;
}

int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	int a[n],x;
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d",&x);
		bsearch(a,n,x);
	}
	
	return 0;
}

