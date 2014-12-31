#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int abs(int a){
	if(a<0) return -a;
	return a;
}

struct point{
	int first ,second;
};
int calcdistance(point a,point b){
	if (abs(a.first-b.first)>abs(a.second-b.second))
		return abs(a.second-b.second);
	else
		return abs(a.first-b.first);
}

int main(){

	int t,n;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<point> p(n);
		
		for (int i = 0; i < n; ++i)
		{
			cin>>p[i].first>>p[i].second;
		}
		int ans;
		/*vector<int> v(n,1),an;

		int ans,min1,temp,minpos;
		for (int count = 0,i=0; count < n; ++count)
		{
			min1=99999999;
			v[i]=0;
			int test=0;
			for (int j = 0; j < n; ++j)
			{
				if(v[j]){
					test=1;
					temp=calcdistance(p[i],p[j]);
					//cout<<" $ "<<temp<<endl;
					if(temp<min1){
						min1=temp;
						minpos=j;
					}
				}
			}
			an.push_back(i);

				i=minpos;
		}

		ans = an[0];
		for (int i = 1; i < an.size(); ++i)
		{
			ans = ans ^ an[i];
			cout<<an[i]<< " : ";
		}*/

		ans = 1;
		for (int i = 2; i <= n; ++i)
		{
			ans = ans ^ i;
		}
		cout<<ans<<endl;
	}
	return 0;
}