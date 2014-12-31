#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int M = 10000007;
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	long long a[n][m],ans[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>a[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		ans[i][m-1]	=a[i][m-1];
	}

	for(int i=m-2;i>=0;i--){
		long long temp=0;
		for(int j=0;j<n;j++){
			temp+=ans[j][i+1];
		}
		temp = temp %M;

		for(int j=0;j<n;j++){
			ans[j][i]=a[j][i]*temp;
			ans[j][i]=ans[j][i]%M;
		}

	}

	long long an=0;
	for (int i = 0; i < n; ++i)
	{
		an+=ans[i][0];
	}
	/*for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<an%M;
	return 0;
}