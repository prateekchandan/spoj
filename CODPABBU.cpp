 #include <iostream>
#include <vector>	
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
unsigned long long modgp(unsigned long long k,unsigned long long r,const unsigned long long &m)
{
	long long res;
	if(k==1)
	{
		return 1;
	}
	if(k==0)
	{
		return 0;
	}		
	if(k&1)
	{
		res=modgp(k-1,r,m);
		res=(res*r + 1)%m;
	}
	else
	{
		res=modgp(k/2,(r*r)%m,m);
		res=((1+r)*res)%m;
	}
	//cout<<r<<" "<<k<<" : "<<res<<endl;
	return res%m;
}

unsigned long long powmod(unsigned long long r,unsigned long long k,unsigned const long long &m)
{
	if(k==0)
		return 1;
	
	if(k==1)
		return r%m;
		
	unsigned long long res=powmod((r*r)%m,k/2,m);
	//res=(res*res)%m;
	if(k&1)
	{
		res=(res*r)%m;
	}
	//cout<<r<<" "<<k<<" : "<<res<<endl;
	return res%m;
}

int main(){
	unsigned long long t,a,d,r,n,m,k,gp,t1,ans;
	cin>>t;
	while(t--)
	{
		cin>>a>>d>>r>>n>>m;
		if(n==1)
		{
			cout<<a%m<<endl;
			continue;
		}
		k=(n-1)/2;
		gp=modgp(k+1,r,m);
		gp=(gp*d)%m;
		t1=powmod(r,k,m);
		t1=(t1*a)%m;
		ans=gp+t1+10*m;
		if(n%2==1)
		{
			ans = ans-d;
		}
	//	cout<<modgp(k,r,m)<<": ";
		cout<<(ans%m)<<endl;
		
	}
	return 0;
}

