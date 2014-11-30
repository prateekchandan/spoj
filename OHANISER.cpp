#include <iostream>
#include <cmath>
const long long M=1000000007;
using namespace std;
int main(int argc, char const *argv[])
{
	long long pow2[1000000];
	pow2[0]=1;
	for (int i = 1; i < 1000000; ++i)
	{
		pow2[i]=2*pow2[i-1];
		if(pow2[i]>M)
			pow2[i]=pow2[i]%M;
	}
	int t,n;
	long long ans;
	cin>>t;
	for (int i = 1; i <= t; ++i)
	{
		cin>>n;
		ans=pow2[n-1]+(n-1)*pow2[n-2];
		if(ans>M)
			ans=ans%M;
		cout<<"Case "<<i<<": "<<ans<<endl;
	}
	return 0;
}