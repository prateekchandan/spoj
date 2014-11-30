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
	vector<int> res(total,1),p(total,1);
	for (int i = 2; i < total; ++i)
	{
		int count=0;
		if(p[i]){
			for (int j = i; j < total; j+=i)
			{
				res[j]+=count;
									
				if(p[j]){
					res[j]++;
					count++;
				}
				p[j]=0;
			}
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