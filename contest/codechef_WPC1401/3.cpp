#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
	int t,n,rem,flag;
	cin>>t;
	while(t--){
		flag=0;
		cin>>n;
		while(n>0)
		{
			rem=n%10;
			n=n/10;
			if(n==0 && rem==1)
				flag=flag||0;
			else if(n!=0 && rem !=0)
				flag=1;
			else
				flag=1;
			
		}
		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	
}

