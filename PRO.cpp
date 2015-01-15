#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
int main(int argc, char const *argv[])
{
	multiset<long long> a;
	multiset<long long>::iterator it;
	long long t,n,ans=0,temp;
	cin>>t;
	while(t--){
		cin>>n;
		while(n--){
			cin>>temp;
			a.insert(temp);
		}
		it = a.end();
		it--;
		ans+=(*it) - *(a.begin());
		a.erase(a.begin());
		a.erase(it);
	}
	cout<<ans;
	return 0;
}