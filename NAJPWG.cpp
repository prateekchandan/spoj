#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int total=100001;

int help(int &n,vector<int> &p,int st,int tot,vector<int> cur){
	int l=cur.size();
	if(tot==l){
		int temp=1;
		for (int i = 0; i < l; ++i)
		{
			temp*=cur[i];
		}
		//cout<<"here "<<temp<<" : "<<n/temp<<endl;
		return n/temp;
	}
	else{
		int ans=0,ps=p.size();
		for (int i = st; i < ps; ++i)
		{
			cur.push_back(p[i]);
			ans+=help(n,p,i+1,tot,cur);
			cur.pop_back();
		}
		//cout<<tot<<": "<<ans<<endl;
		return ans;
	}
}

int calcans(int &n,vector<int> &p){
	int totans=0,temp1;
	for(int i=1;i<=p.size();++i){
		vector<int> temp;
		temp1=help(n,p,0,i,temp);
		//cout<<i<<" : "<<temp1<<endl;
		if(i&1)
			totans+=temp1;
		else
			totans-=temp1;
	}
	return totans;
}

int main(int argc, char const *argv[])
{
	/*vector<int> v;
	int n=24;
	v.push_back(2);
	v.push_back(3);
	cout<<calcans(n,v)<<endl;;*/
	vector<int> p(total,1),res(total,0);
	p[0]=0; p[1]=0;
	vector<vector<int> > v(total);
	for (int i = 2; i < total; ++i)
	{	
		if(p[i]){
			for (int j = i; j < total; j+=i)
			{
				v[j].push_back(i);
				p[j]=0;
			}
		}
	}

	for (int i = 1; i < total; ++i)
	{
		res[i]=calcans(i,v[i]);
	}

	for (int i = 1; i < total; ++i)
	{
		res[i]+=res[i-1];
		cout<<res[i]<<"|";
	}


	int t,n;
	cin>>t;
	for(int no=1;no<=t;no++){
		cin>>n;
		cout<<"Case "<<no<<": "<<res[n];
		if(no!=t)
			cout<<endl;
	}
	return 0;

	/********** THE END *****************/
}