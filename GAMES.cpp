#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int gcd(int a,int b){
	if(a%b==0)
		return b;
	else return gcd(b,a%b);
}
int main(){
	std::ios_base::sync_with_stdio(false);
	string a;
	int t,n,temp;
	int b,div;
	cin>>t;
	while(t--){
		cin>>a;
		b=0;div=1;
		bool flag=false;
		for (int i = 0; i < a.length(); i++)
		{
			if(flag){
				b=b*10 + a[i]-48;
				div*=10;
			}
			if(a[i]=='.'){
				flag=true;
			}
		}
		
		temp=gcd(b,div);
		cout<<div/temp<<endl;
	}
	return 0;
}
