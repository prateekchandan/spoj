#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <string.h>
#include <algorithm>

using namespace std;
const long long M = 1000000007;
const int total=1000001;

long long powmod(long long n,long long p){
	if(p==0)
		return 1;
	else if(p==1)
		return n%M;

	long long p2=p/2;
	long long res=powmod(n,p2);
	res=res*res;
	if(res>M)
		res=res%M;
	if(p&1){
		res=res*n;
		if(res>M)
		res=res%M;
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int *facmod= new int[total*2];
	long long temp;
	facmod[0]=1;
	facmod[1]=1;
	for (long long i = 2; i < total*2; ++i)
	{
		temp=i*facmod[i-1];
		if(temp>M)
			temp=temp%M;

		facmod[i]=temp;
	}

	long long *invfacmod=new long long[total];

	for (int i = 0; i < total; ++i)
	{
		invfacmod[i]=powmod(facmod[i],M-2);
	}

	int t;
	cin>>t;
	long long x,y,res;
	while(t--){
		cin>>x>>y;
		res=facmod[x+y]*invfacmod[x];
		if(res>M)
			res=res%M;
		res*=invfacmod[y];
		if(res>M)
			res=res%M;
		cout<<res<<endl;
	}

	delete []facmod;
	delete []invfacmod;
	return 0;
}