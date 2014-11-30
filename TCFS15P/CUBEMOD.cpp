#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	long long a,b,p,res,count=0,t1,t2;
	
	while(t--)
	{
		res=0;
		count=0;
		cin>>a>>b>>p;
		vector<long long> x(p,0);
		for (long long i = 0; i < p; i++)
		{
			if((i*i*i)%p == 1)
				count++;
			
			x[i]=count;
			
		}
		
		t1=b/p;
		t2=b%p;
		res=t1*count+x[t2];
		
		a--;
		
		t1=a/p;
		t2=a%p;
		res=res-(t1*count+x[t2]);
		
		
		cout<<res<<endl;
	}
	
	return 0;
}

