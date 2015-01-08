#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const long long M=1000000007;
vector<long long> matmult(vector<long long> a,vector<long long> b){
	vector<long long> ans(4);
	ans[0]=a[0]*b[0]+a[1]*b[2];
	ans[1]=a[0]*b[1]+a[1]*b[3];
	ans[2]=a[2]*b[0]+a[3]*b[2];
	ans[3]=a[2]*b[1]+a[3]*b[3];

	for (int i = 0; i < 4; ++i)
	{
		if(ans[i]>M)
			ans[i]=ans[i]%M;
	}
	return ans;
}
vector<long long> pown(int n){
	
	vector<long long> v(4);
	v[0]=1; v[1]=1; v[2]=1; v[3]=0;
	if(n <= 1)
		return v;

	
	vector<long long> m;
	m=pown(n/2);
	m=matmult(m,m);
	
	if(n&1)
		m=matmult(m,v);

	return m;
}


int fibsum(int n){
	if(n<=0)
		return 0;

	vector<long long> v=pown(n+1);

	return v[0]-1;

}

int main(int argc, char const *argv[])
{
	long long n,a,b;
	cin>>n;
	
	while(n--){
		cin>>a>>b;
		a=fibsum(a-1);
		b=fibsum(b);
		a=b-a;
		if(a<0);
		a=a+M;
		cout<<a<<endl;
	}
	return 0;
}