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
				for (int it = 1; it < maxi; it++)
		{
			cout<<prev[it]<< " ";
			
		}
		cout<<endl;
		for (long long ki = 1; ki < maxi; ki++)
		{
			res=0;
			long long k=ki;
			if(k>sq)
				k=m/(maxi-k);
			for (int j = 1; j <= sq ; j++)
			{
				a1=m/j;
				if(j<=k)
					res+=prev[maxi-j];
				
				if(res>mod)
					res=res%mod;
					
				a2=min(k,a1);
				
				a2=a2-max(m/(j+1),sq);
				
				if(a2>0)
				{
					a1=a2*prev[j];
					if(a1>mod)
						a1=a1%mod;
					
					res+=a1;
				}
				
				if(res>mod)
					res=res%mod;
			}
			
			a[ki]=res;
			
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
