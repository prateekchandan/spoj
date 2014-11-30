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
	long long t,a,b,c,d,num,den,gc;
	cin>>t;
	for (int i = 1; i <= t; ++i)
	{
		cin>>a>>b>>c>>d;
		if(a+b==0)
		{
			cout<<"Case "<<i<<": 0"<<endl;
			continue;
		}
		num=(a*(c+1))+(b*(d+1));
		den=(a+b)*(c+d+1);
		gc=gcd(num,den);
		if(gc==0)
			cout<<"Case "<<i<<": 0"<<endl;
		else
			cout<<"Case "<<i<<": "<<num/gc<<"/"<<den/gc<<endl;
	}
	return 0;
}