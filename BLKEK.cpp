#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	int n;
	cin>>n;

	string s;
	int l;
	while(n--)
	{
		cin>>s;
		l = s.size();
		vector<int> pre(l,0),post(l,0);

		if(pre[0]=='K')
			pre[0] = 1;

		for (int i = 1; i < l; ++i)
		{
			if(s[i] == 'K')
				pre[i] = 1;

			pre[i] += pre[i-1];
		}

		if(post[l-1]=='K')
			post[l-1] = 1;

		for (int i = l-2; i >= 0; --i)
		{
			if(s[i] == 'K')
				post[i] = 1;

			post[i] += post[i+1];
		}

		int ans = 0;


		for (int i = 0; i < n; ++i)
		{
			if(s[i] == 'E')
				ans+= post[i] * pre[i];
		}

		cout<<ans<<endl;

	}
	return 0;
}