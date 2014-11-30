#include <iostream>
#include <cstdio>
using namespace std;
const unsigned int M = 1000000007;

unsigned int temp[5][5];
unsigned int memo[31][5][5];

void matcopy(unsigned int a[5][5],unsigned int b[5][5]){
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			a[i][j]=b[i][j];
		}
	}	
}
void matmult5(unsigned int a[5][5],unsigned int b[5][5],unsigned int c[5][5]){
	unsigned long long sum=0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			sum=0;
			for (int k = 0; k < 5; k++)
			{
				sum+=((unsigned long long)a[i][k])*((unsigned long long)b[k][j]);
				if(sum > M){
					sum = sum % M;
				}
			}
			c[i][j]=sum;
		}
	}
}

int sum(int n){
	if(n<3) return 0;
	if(n==3) return 1;
	unsigned int p[5][5] = {{1,1,1,1,1},
								{0,1,1,1,1},
								{0,1,0,0,0},
								{0,0,1,0,0},
								{0,0,0,1,0}};
	matcopy(temp, p);
	n-=4;
	int ind = 0;
	while(n){
		if(n&1){
			matcopy(temp, p);
			matmult5(temp, memo[ind], p);
		}
		ind++;
		n = n>>1;
	}
	return p[0][0] + p[0][1];
}
void powm(unsigned int a[5][5],int n){
	if(n==1)
		return;
	unsigned int c[5][5];
	matcopy(c,a);	
	powm(c,n>>1);
	
	if(n&1){
		matmult5(c,c,temp);
		matcopy(c,a);	
		matmult5(temp,c,a);
		return;
		
	}
	else{
		matmult5(c,c,a);
		return;	
	}
	
	/*unsigned int p[5][5] = {{1,1,1,1,1},
								{0,1,1,1,1},
								{0,1,0,0,0},
								{0,0,1,0,0},
								{0,0,0,1,0}};
	matcopy(temp, p);
	n--;
	while(n){
		if(n&1) matmult5(
	}*/
}

void memoization(){
	unsigned int a[5][5]={{1,1,1,1,1},
								{0,1,1,1,1},
								{0,1,0,0,0},
								{0,0,1,0,0},
								{0,0,0,1,0}};
	
	for(int i = 0; i < 31; i++){
		matcopy(memo[i], a);
		matmult5(a,a,temp);
		matcopy(a,temp);
	}
}

int main(){
	memoization();
	int t,_m,_n;
	scanf("%d",&t);
	unsigned int a[5][5]={{1,1,1,1,1},
								{0,1,1,1,1},
								{0,1,0,0,0},
								{0,0,1,0,0},
								{0,0,0,1,0}};
	unsigned int n[5][5],m[5][5];
	while(t--){
		scanf("%d",&_m);
		scanf("%d",&_n);
		
		/*_n-=3;
		_m-=4;
		
		matcopy(n,a);
		matcopy(m,a);
			
		if(_n<1)
			n[0][1]=0;
		else
			powm(n,_n);
		
		if(_m<1)
			m[0][1]=0;
		else
			powm(m,_m);
		
		if(_n < 0)
			m[0][1]++;
			
		if(_m < 0)
			n[0][1]++;*/
		
		//print5(m);
		//print5(n);
	
		int ans = M+sum(_n);
		ans -= sum(_m-1);
		printf("%d\n",ans%M);
		
	}
}

