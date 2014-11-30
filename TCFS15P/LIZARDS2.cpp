#include <bits/stdc++.h>
using namespace std;
int main(){
	std::ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	long long n,q,r;
	while(t--){
		cin>>n;
		r=n*(n-1);
		if(r%8==0)
			q=8;
		else if(r%4==0)
			q=4;
		else if(r%2==0)
			q=2;
		else
			q=1;
		cout<<r/q<<"/"<<8/q<<endl;
	}
	return 0;
}

