#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		sort(a.begin(),a.end());
		int temp=0,maxi=0,last=-1;
		for (int i = 0; i < n; ++i)
		{
			if(last==a[i]){
				temp+=a[i];
			}
			else{
				if(temp>maxi)
					maxi=temp;
				temp=a[i];
			}
			last=a[i];
		}
		if(temp>maxi)
			maxi=temp;
		cout<<maxi<<endl;
	}
	return 0;
}