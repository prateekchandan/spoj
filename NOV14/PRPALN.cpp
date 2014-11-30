#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int l=s.size(),st=0,en=l-1;
		while(st<en){
			if(s[st]==s[en])
			{
				st++;
				en--;
			}
		}
		if(st>=en)
		{
			cout<<"YES\n";
			continue;
		}
		
	}
	return 0;
}

