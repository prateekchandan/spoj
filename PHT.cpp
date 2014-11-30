#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	long long t,a,gc;
	cin>>t;
	for (int i = 1; i <= t; ++i)
	{
		cin>>a;
		gc=sqrt(a+1.0);
		cout<<"Case "<<i<<": "<<gc-1<<endl;
	}
	return 0;
}