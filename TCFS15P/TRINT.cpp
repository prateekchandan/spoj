#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,n,res=0,m,temp,cum,pre;

	cin>>t;
	while(t--){
		pre=-1;
		cin>>n>>m;
		vector<int> af(1000001,0),ac(1000001,0),a(n),au;
		
		for (int i = 0; i < n; i++)
		{
			cin>>a[i];
			af[a[i]]++;
			
		}
		cum=0;
		for (int i = 0; i < 1000001; i++)
		{
			if(af[i]>0)
				cum++;
			ac[i]+=cum;
		}
		
	
		sort(a.begin(),a.end());
		for (int i = 0; i < n; i++)
		{
			if(pre==-1)
			{
				au.push_back(a[i]); pre++;
			}
			else if(au[pre]!=a[i]){
				au.push_back(a[i]); pre++;
			}
		}
		// au has distinct nos;
		// af has all frequencies
		// ac[i] has no of numbers till i
		
		int l=au.size();
		
		res=0;
		
		for (int i = 0; i < l; i++)
		{
			if(af[au[i]]>=3 && (au[i]*3) <= m ){
				res++;
			}
			if(af[au[i]]>=2){
				pre=m-2*au[i];
				//cout<<au[i]<<" "<<pre<<"* ";
				if(pre>au[i]){
					res+=ac[pre]-ac[au[i]];
				}
			}
			
			pre=m-au[i];
			if(pre <= au[i]) { break;}
			for (int j = i+1; j<l && au[j] <= pre; j++)
			{
				if(af[au[j]]>=2 && (au[j]*2) <=pre)
					res++;
				
				temp = pre-au[j];
				if(temp>au[j]){
					res+=ac[temp]-ac[au[j]];
				}
			}
			
		}
		
		cout<<res<<endl;
		
		
		
	}
	return 0;
}

