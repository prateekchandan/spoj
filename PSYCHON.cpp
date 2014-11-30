#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int pl;
vector<int> allp;
bool primes[10000001];
bool psy[10000001];
int main()
{
	for (int i = 0; i < 10000001; i++)
	{
		primes[i]=1;
	}
	pl=0;
	primes[0]=primes[1]=0;
	for (int i = 2; i < 10000001; i++)
	{
		if(primes[i])
		{
			pl++;
			allp.push_back(i);
			for (int j = i+i; j < 10000001; j+=i)
			{
				primes[j]=0;
			}
			
		}
	}
	cout<<pl;
	/*
	int t,no;
	cin>>t;
	while(t--)
	{
		scanf("%d",&no);
		if(psy[no]>0)
		printf("Psycho Number\n");
		else
		printf("Ordinary Number\n");
	}*/
	
}

