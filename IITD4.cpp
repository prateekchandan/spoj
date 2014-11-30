#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	vector<vector<int> > alldiv(100001);
	int p[100001];
	for (int i = 0; i < 100001; i++)
	{
		p[i]=1;
	}
	p[0]=0;p[1]=1;
	for (int i = 2; i < 100001; i++)
	{
		alldiv[i].push_back[i];
		if(p[i]==1)
		for (int j = i+i; j < 100001; j+=i)
		{
			alldiv[j]
		}
		
	}
	
	
	return 0;
}
