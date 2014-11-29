#include <cstdio>
using namespace std;
long long M = 1000000007;
int main(){
	M=3*M;
	unsigned long long a;
	while(scanf("%lld",&a)!=EOF){
		unsigned long long ans=2,temp=1;
		while(a>0){
			if(a&1){
				temp=(ans*temp)%M;
			}
			ans=(ans*ans)%M;
			a = a/2;
		}
		printf("%llu\n",temp/3+1);
	}
	return 0;
}
