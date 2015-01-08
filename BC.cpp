#include <stdio.h>
int main(int argc, char const *argv[])
{
	int t,i;
	long long x,y,z;
	scanf("%d",&t);
	long long ans[2005],temp;
	ans[1]=0;
	ans[2]=1;
	for (int i = 3; i < 2005; ++i)
	{
		temp=i/2;
		if(i&1)
			temp++;
		ans[i]=ans[temp]+1;
	}
	for (i = 1; i <= t; ++i)
	{
		scanf("%lld",&x);
		scanf("%lld",&y);
		scanf("%lld",&z);
		printf("Case #%d: %lld %lld\n",i,(x*y*z-1),(ans[x]+ans[y]+ans[z]));
	}
	return 0;
}