#include <bits/stdc++.h>
using namespace std;
int ispali(string s){
	int l=s.size();
	for (int i = 0; i < l; i++)
	{
		if(s[i]!=s[l-1-i])
			return 0;
	}
	return 1;
}
int main(){
	string s;
	int l,st,en;
	cin>>s;
	l=s.size();
	st=0;en=l-1;
	while(s[st]==s[en]){
		st++;
		en--;
		if(st>=en)
		{
			cout<<"Yes";
			return 0;
		}
	}
	{
		for (int i = st+1; i < en; i++)
		{
			string new1=s,new2=s;
			char c;
			
			int flag=1;
			for (int j = st; j <= en ; j++)
			{
				int a1=j,a2=l-1-j;
				if(a1<=i)
					a1=i-a1+st;
				if(a2<=i)
					a2=i-a2+st;
				
				if(s[a1]!=s[a2])
				{
					flag=0;
					break;
				}
			}
			if(flag){
				cout<<"Yes";
				return 0;
			}
			
			flag=1;
			for (int j = st; j <= en ; j++)
			{
				int a1=j,a2=l-1-j;
				if(a1>=i)
					a1=en-a1+i;
				if(a2>=i)
					a2=en-a2+i;
				
				if(s[a1]!=s[a2])
				{
					flag=0;
					break;
				}
			}
			
			if(flag){
				cout<<"Yes";
				return 0;
			}
			
		}
		
	}
	cout<<"No";
	return 0;
}
