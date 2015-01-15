#include <iostream>
#include <vector>
using namespace std;

int main(){
	int t;
	int n,temp,mi=-1,ma=10;
	cin>>t;
	for (int it = 1; it <= t; ++it)
	{
		mi=10; ma=-1;
		vector<int> v,v1,v2;
		std::vector<int>::iterator ite;
		cin>>n;
		if(n==0){
			cout<<"Case #"<<it<<": 0 0\n";
		}
		while(n>0){
			temp=n%10;
			ite = v.begin();
			v.insert(ite,temp);			
			n/=10;
		}

		for (int i = 0; i < v.size(); ++i)
		{
			if(v[i]<mi && v[i]!=0)
				mi=v[i];
			if(v[i]>ma)
				ma=v[i];
		}
		v1=v; v2=v;
		temp=v[0];
		v1[0]=mi;
		v2[0]=ma;
		for (int i = v.size()-1; i >=0; --i)
		{
			if(v1[i]==mi){
				v1[i]=temp;
				break;
			}
		}
		for (int i = v.size()-1; i >=0; --i)
		{
			if(v2[i]==ma){
				v2[i]=temp;
				break;
			}
		}

		cout<<"Case #"<<it<<": ";
		for (int i = 0; i < v.size(); ++i)
		{
			cout<<v1[i];
		}
		cout<<" ";
		for (int i = 0; i < v.size(); ++i)
		{
			cout<<v2[i];
		}
		cout<<"\n";
	}
	return 0;
}