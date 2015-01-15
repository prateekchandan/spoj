#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstring>

#define fore(i,n) for(int i=0;i<n;i++)
#define forn(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		fore(i,n){
			cin>>a[i];
		}
		sort(a.begin(),a.end());
		long long cost=0;
		int temp=0,flip=0;
		for(int i=n-1;i>=0;i-=4){
			
			if(i>=0){
				cost+=a[i];
			}
			if(i>0){
				cost+=a[i-1];
			}
		}
		cout<<cost<<endl;
	}
	return 0;
}
