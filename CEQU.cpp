#include <iostream>
using namespace std;
long gcd(long long a , long long b){
	if(b==0 || a==0)
		return 0;
	if(b%a==0)
		return a;
	else 
		return gcd(b%a,a);
}
int main(int argc, char const *argv[])
{
	long long t,a,b,c,gc;
	cin>>t;
	for (int i = 1; i <= t; ++i)
	{
		cin>>a>>b>>c;
		gc=gcd(a,b);
		if(c%gc==0)
			cout<<"Case "<<i<<": Yes"<<endl;
		else
			cout<<"Case "<<i<<": No"<<endl;
	}
	return 0;
}