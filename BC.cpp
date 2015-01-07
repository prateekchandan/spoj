#include <stdio.h>
int main(int argc, char const *argv[])
{
	int t,i;
	long long x,y,z;
	scanf("%d",&t);
	for (i = 1; i <= t; ++i)
	{
		scanf("%lld",&x);
		scanf("%lld",&y);
		scanf("%lld",&z);
		printf("Case #%d: %lld %lld\n",i,(x*y*z-1),(x+y+z-3));
	}
	return 0;
}