#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
int main(){
	std::ios_base::sync_with_stdio(false);
	int t,n,m,a,res;
	cin>>t;
	while(t--){
		cin>>n>>m>>a;
		a--;
		res=(a+m)%n;
		cout<<(res+1)<<endl;
	}
	return 0;
}
