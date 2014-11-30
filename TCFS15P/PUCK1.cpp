#include <bits/stdc++.h>
#define even(n) n%2==0
#define odd(n) n%2==1
using namespace std;
struct node{
	int even,odd;
	vector<pair<int,int> > op;
	node(){
		even=0; odd=0; 
	}
};
int main(){
	int n,k,sqv;
	cin>>n;
	sqv=(int)sqrt((double)n);
	vector<node> a(n),sq(sqv+1);
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	
	cin>>k;
	int x,y,op,opid;
	char c;
	for (int i = 0; i < k; i++)
	{
		op=0;
		cin>>c>>x>>y;
		x--; y--;
		opid=i+1;

		if(c=='M')
		{
			op=0;
		}
		if(c=='E')
			op=1;
		else if(c=='O')
			op=2;
		else if(c=='I')
			op=3;
	
		applyop(a,sq,x,y,op,opid);
	}
	

	
	return 0;
}

