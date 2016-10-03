#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

#define SIZE 1000001
int main(){
	int n;

	vector<int> ans(SIZE,0);

	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 2;
	int nextpow = 4,pow = 1;
	
	for (int i = 4; i < SIZE; ++i)
	{
		if(i==nextpow)
		{
			pow = nextpow;
			nextpow *= 2;
		}

		ans[i] = 2 * (i - pow) + 1;
		ans[i] = (ans[i] % i)+ 1;
	}

	int k;

	cin>>k;

	while(k>0)
	{
		cout<<ans[k]<<endl;
		cin>>k;
	}

	return 0;
}