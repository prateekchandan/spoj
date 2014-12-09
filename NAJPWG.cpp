#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int total=100001;
int main(int argc, char const *argv[])
{
	vector<int> res(total,0),p(total,1);
	for (int i = 2; i < total; ++i)
	{	
		for (int j = i; j < total; j+=i)
		{
			res[j]++;
		}	
	}
	for (int i = 1; i < total; ++i)
	{
		res[i]+=res[i-1];
	}


	int t,n;
	cin>>t;
	for(int no=1;no<=t;no++){
		cin>>n;
		cout<<"Case "<<no<<": "<<res[n];
		if(no!=t)
			cout<<endl;
	}
	return 0;
}