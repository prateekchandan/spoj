#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
	int a[1000001],k=1,it=2;
	a[0]=1;
	a[1]=2;
	
	for (int i=1; 1;)
	{
		for (int j = 0; j < a[k-1]; j++)
		{
			a[i]=it;
			i+=1;
			
			if(i>1000000)
			break;
			//
		}
		//cout<<i<<":"<<it<<":"<<k<<"&"<<a[k] <<endl;
		k+=1;
		it+=1;
		
		if(i>1000000)
		break;
	}
	//cout<<it<<" &&\n";
	/*for (int i = 0; i < 100; i++)
	{
		cout<<a[i]<<" ";
	}*/
	int t,n;
	cin>>t;
	for (int i = 1; i <=t ; i++)
	{
		cin>>n;
		cout<<"Case #"<<i<<": "<<a[n-1]<<endl;
	}
	
	return 0;
	
}
