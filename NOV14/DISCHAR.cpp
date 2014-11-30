#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int a[256],count=0;
		for (int i = 0; i < 256; i++)
		{
			a[i]=0;
		}
		for (int i = 0; i < s.size(); i++)
		{
			if(a[s[i]]==0){
				count++;
				a[s[i]]=1;
			}
		}
		cout<<count<<endl;
		
	}
	return 0;
}
