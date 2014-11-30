#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

int main(){
	long long int n,mini=0,b[100001],a[100001],temp=0,t1;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i]>>b[i];
		if(temp<a[i])
		{
			t1=a[i]-temp;
			temp+=t1;
			mini+=t1;
		}
		temp-=a[i];
		temp+=b[i];
	}
	cout<<mini<<endl;
	return 0;
}
