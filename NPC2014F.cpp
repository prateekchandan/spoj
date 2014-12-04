#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int l;
	int t;
	cin>>l;
	string s;
	cin>>s;
	vector<int> req(26,0);
	cin>>t;
	int r;
	char c;
	for (int i = 0; i < t; ++i)
	{
		cin>>r>>c;
		req[c-'a']=r;
	}

	int st=0,en=0;

	int minsize=9999999,found=0,temp;
	while(st<=en && en < l){
		int ok=1;
		for (int i = 0; i < 26; ++i)
		{
			if(req[i]>0){
				ok=0;
				break;
			}
		}

		if(ok){
			found=1;
			temp=en-st;
			if(temp<minsize)
				minsize=temp;

			req[s[st]-'a']++;
			st++;
		}
		else{
			req[s[en]-'a']--;
			en++;
		}
	}
	if(found)
		cout<<minsize;
	else
		cout<<"Andy rapopo";
	

	return 0;
}