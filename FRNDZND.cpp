#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	int x,y;
	while(q--)
	{
		cin>>x>>y;

		if(x==y)
			cout<<a[x-1]<<endl;
		else 
			cout<<"0\n";
	}
	return 0;
}
