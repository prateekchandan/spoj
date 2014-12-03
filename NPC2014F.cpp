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

	int st=-1,en=0;

	int minsize=9999999,found=0;
	req[s[0]-'a']--;
	while(st < en && en < l){
		int ok=1;
		for (int i = 0; i < 26; ++i)
		{
			if(req[i]>0){
				ok=0;
				break;
			}
		}

		if(ok){

		}
		else{
			req[s[en]-'a']--;
			en++;
		}
	}


	return 0;
}