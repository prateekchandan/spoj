#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,maxv=0,count,gmax=0;
		cin>>n;
		vector<int> a(n),b;
		for (int i = 0; i < n; i++)
		{
			cin>>a[i];
		}
		sort(a.begin(),a.end());
		b=a;
		count=0;
		while(1){
			count++;
			maxv=0;
			int size=b.size();
			cout<<size<<" "<<endl;
			vector<int> maxi(size,0),c(size,0);
			for (int i = 0; i < size; i++)
			{
				int index;
				maxv=0;
				for (int j = 1; j <= b[i] && i - j >= 0  ; j++)
				{
					if(maxi[i-j]>maxv && b[i]>=maxi[i-j])
					{
						maxv=maxi[i-j];
						index=i-j;
					}
				}
				c[index]=1;
				maxi[i]=maxv+1;
			}
			if(gmax>maxi[size-1])
				gmax=maxi[size-1];
			
			vector<int> temp;
			bool check=true;
			for (int i = 0; i < size; i++)
			{
				if(c[i]==0){
					temp.push_back(b[i]);
					check=false;
				}
			}
			
			if(check)
			break;
			b=temp;
				
		}
		
		cout<<gmax<<" "<<count<<endl;
	
	}
	return 0;
}
