#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;
long long gcd(long long a,long long b){
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
int main(){
	int t,n;
	long long a,b,c;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		if(n>2)
			a=2*n-3;
		else if(n==2)
			a=1;
		else
			a=0;
			
		a+= ((n*(n+1))/2) + n + (((n-1)/2)*(((n-1)/2)-1)) + (n-(2*((n-1)/2)))*((n-1)/2);
		b=6*n*n*n;
		c=gcd(a,b);
		
		printf("%lld/%lld\n",a/c,b/c);
	}
	return 0;
}

