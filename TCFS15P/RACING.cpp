#include <bits/stdc++.h>
using namespace std;
const long long Mod=1000000007;

long long nc[100][100];

void calc_nc(int l){
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l; j++)
		{
			nc[i][j]=0;
		}
		
	}
	for (int i = 0; i < l; i++)
	{
		nc[i][i]=1;
		nc[i][0]=1;
	}
	for (int i = 1; i < l; i++)
	{
		for (int j = 1; j < l; j++)
		{
			nc[i][j]=nc[i-1][j]+nc[i-1][j-1];
			if(nc[i][j]>Mod)
				nc[i][j]%=Mod;
				
			//cout<<nc[i][j]<<" ";
		}
		//cout<<endl;
	}
	
	
}

long long ncr(long long n,long long r){
	return nc[n][r];
}
long long mypow2(long long n){
	if(n==0)
		return 1;
	if(n==1)
		return 2;
	long long res=mypow2(n/2);
	res=res*res;
	if(res>Mod)
		res=res%Mod;
	if(n%2==1)
	{
		res=res*2;
	}
	if(res>Mod)
		res=res%Mod;
	return res;
}
int main(){
	std::ios_base::sync_with_stdio(false);
	
	calc_nc(100);
	
	
	long long n , r , s,res;
	cin>>n>>r>>s;
	
	if(s>r){
		s=s+r;
		r=s-r;
		s=s-r;
	}
	
	if(r < n && s < n){
		cout<<"0";
		return 0;
	}
	
	if(r==n){
		if(s>=n-1)
		{
			cout<<"0";
			return 0;
		}
		cout<<ncr(n-1+s,s);
		return 0;
	}
	
	if((r-s) !=2)
	{
		cout<<"0";
		return 0;
	}
	
	res=ncr(2*n-2,n-1)%Mod;
	res*=mypow2(s-n+1);
	res=res%Mod;
	cout<<res;
	return 0;
}

