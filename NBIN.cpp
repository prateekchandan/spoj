#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
string binadd(string s1,string s2){
	int rem=0,sum;
	int l1=s1.length(),l2=s2.length(),i1,i2;
	string res="",res1="";
	for(int i=1;i<=l1||i<=l2;i++)
	{
		if(i>l1){
			sum=s2[l2-i]+rem-48;
		}	
		else if(i>l2)
		{
			sum=s1[l1-i]+rem-48;
		}
		else{
			sum=s1[l1-i]+s2[l2-i]+rem-96;
		}
		res=res+(char)(sum%2 + 48);
			rem=sum/2;
	}
	for(int i=res.length()-1;i>=0;i--)
		res1=res1+res[i];
	return res1;
}
int main(){
	int t;
	long long n,temp;
	long long fib[100],a1=1,a2=1;
	for(int i=0;i<80;i++){
		fib[i]=a2;
		a2=a1+a2;
		a1=a2-a1;
	}
	cin>>t;
	while(t--)
	{
		cin>>n;
		string ans="",current;
		while(n>0){
			temp=0;
			for(;fib[temp+1]<=n;temp++);
			n-=fib[temp];
			current="1";
			for(;temp>0;temp--){
				current=current+"0";
			}
			
			ans=binadd(ans,current);
		}
		cout<<ans<<endl;	
	}
	return 0;
}
