#include <bits/stdc++.h>
using namespace std;
long long mod=1000000007;
long long n,m;
long long fun(long long i,long long k){
	
	if(k==0)
	{
		return 0;
	}
	if(i==n){
		return k;
	}
	
	long long res=0,sq,a1,a2;
	sq=(long long)sqrt((double)m);
	for (int j = 1; j <= sq ; j++)
	{
		a1=m/j;
		if(j<=k)
			res+=fun(i+1,a1);
		
		if(res>mod)
			res=res%mod;
			
		a2=min(k,a1);
		
		a2=a2-max(m/(j+1),sq);
		
		if(a2>0)
		{
			a1=a2*fun(i+1,j);
			if(a1>mod)
				a1=a1%mod;
			
			res+=a1;
		}
		
		if(res>mod)
			res=res%mod;
	}
	if(res>mod)
		res=res%mod;
		
	return res;
}

int main(){
	
	long long res=0;
	cin>>n>>m;
	cout<<fun(1,m)<<endl;
	
	return 0;
}
