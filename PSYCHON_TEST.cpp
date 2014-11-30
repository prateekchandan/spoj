#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int *psy=new int[10000001];
	bool *p=new bool[10000001];
	
	for (int i = 0; i <= 10000000; i++)
	{
		psy[i]=0;
		if(i<3163)
		p[i]=true;
	}
	psy[1]=0;
	for (int i = 2; i < 10000001; i++)
	{
		if(p[i])
		{
			for (int j = i+i; j < 10000001 ; j+=i)
			{
				p[j]=false;
			}
		}
	}
	for (int i = 2; i < 3163; i++)
	{
		if(p[i])
		{
			//cout<<i<<endl;
			bool t=false;
			for (long long k=i,m=1; k<=10000000 ;t^=1,m++)
			{
					int sum;
					if(m==1)
						sum=1;
					else
						sum=2;
						
				for (int j = k; j <= 10000000 ; j+=k)
				{
					
					if(t)
					psy[j]+=sum;
					else
					psy[j]-=sum;
				}
				k*=i;
			}
		}
	}
	
	int t,no;
	cin>>t;
	while(t--)
	{
		scanf("%d",&no);
		//cout<<psy[no];
		if(psy[no]>0)
		printf("Psycho Number\n");
		else
		printf("Ordinary Number\n");
	}
	/*for (int i = 0; i < 10000; i++)
	{
		if(psy[i]>0)
		cout<<i<<":"<<psy[i]<<"\n";
	}*/
	
	delete []p;
	delete []psy;
}

