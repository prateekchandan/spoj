#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<int> > graph(1001);
int traverse[1001];
int n;

void resetgraph(){
	for (int i = 0; i < 1001; i++)
	{
		traverse[i]=0;
		vector<int> x;
		graph[i]=x;
	}
	
}

void DFS(int t,vector<int> &a)
{
	if(traverse[t]==1)
	return;
	
	a.push_back(t);
	traverse[t]=1;
	for (int i = 0; i < graph[t].size(); i++)
	{
		if(traverse[graph[t][i]]==0){
			DFS(graph[t][i],a);
		}
	}
}

void sortme(int *a,vector<int> &x){
	vector<int> b(x.size()),c(x.size());
	for (int i = 0; i < x.size(); i++)
	{
		b[i]=a[x[i]];
		c[i]=x[i];
	}
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	for (int i = 0; i < b.size(); i++)
		a[c[i]]=b[i];
	{
		
	}
}

void sortg(int* a)
{
	for (int i = 0; i < n; i++)
	{
		if(traverse[i]!=1){
			vector<int> x;
			DFS(i,x);
			
			
			sortme(a,x);
		}
	}
	
}
int main(){
	int t,m,t1,t2;
	cin>>t;
	while(t--)
	{
		resetgraph();
		cin>>n>>m;
		int a[n];
		
		for (int i = 0; i < n; i++)
		{
			cin>>a[i];
		}
		
		for (int i = 0; i < m; i++)
		{
			cin>>t1>>t2;
			graph[t1-1].push_back(t2-1);
			graph[t2-1].push_back(t1-1);
		}
		
	
		sortg(a);
		
		for (int i = 0; i < n; i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
		
	}
	return 0;
}
