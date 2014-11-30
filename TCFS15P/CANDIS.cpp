#include <bits/stdc++.h>
using namespace std;
long long mod=1000000007;
long long n,m;
long long fun(){
	
	long long res,sq,a1,a2,pres,maxi;
	sq=(long long)sqrt((double)m);
	maxi=2*sq+1;
	vector<long long> a(maxi,0),prev(maxi,0);;
	for (int i = 1; i <= sq; i++)
	{
		prev[i]=i;
		prev[maxi-i]=m/i;
	}
	pres=sq;
	for (int i = n-1; i >= 1 ; i--)
	{
		
		res=0;
		for (long long k = 1; k < maxi; k++)
		{
			
			if(k<=sq)
				res+=prev[maxi-k];
			else{
				long long l,diff=0;
				l=maxi-k;
				if(m/l != l)
					diff=m/l - m/(l+1);
				if(res>mod)
					res%=mod;
				
				if(diff>0)
				res+=diff*prev[maxi-k];
				
			}
			if(res>mod)
				res%=mod;
			a[k]=res;
		}
		
		prev=a;
	}
	
	res=prev[maxi-1];
	if(res>mod)
		res=res%mod;
		
	return res;
}

int main(){
	
	long long res=0;
	cin>>n>>m;
	cout<<fun()<<endl;
	
	return 0;
}
