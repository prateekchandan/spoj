#include <bits/stdc++.h>
using namespace std;
int main(){
	std::ios_base::sync_with_stdio(false);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n%8==0)
		{
			cout<<"YES\n";
			continue;
		}
		if(n<6 || n%2==1 || n==10)
		{
			cout<<"RIDICULOUS\n";
			continue;
		}
		if(n==6 || n==12 || n==18){
			cout<<"NO\n";
			continue;
		}
		else
		{
			cout<<"YES\n";
			continue;
		}
		
	}
	return 0;
}

