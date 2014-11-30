#include <iostream>
#include <vector>

using namespace std;
int main(){
	long long t,n;cin>>t;
	for (int i = 0; i < t; i++)
	{
		cin>>n;
		n++;
		long long ans= (n*(n+1))/2;
		cout<<ans-1<<endl;
	}
	
	return 0;
}
