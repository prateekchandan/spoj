#include <bits/stdc++.h>

using namespace std;

int DFSAssign(vector<int> &tree, vector<vector<int> > &adj, int ind)
{
	int count = 1;
	tree[ind] = 1;
	for(int i = 0; i < adj[ind].size(); ++i)
	{
		if(tree[adj[ind][i]] == 0)
		{
			count += DFSAssign(tree, adj,adj[ind][i]);
		}
	}
	return count;
}


int main()
{
	int prime[100001];
	int p[1500000], n = 1500000;
	for(int i = 2; i < n; ++i)
	{
		p[i] = 0;
	}
	p[0] = 1; p[1] = 1;
	
	for(int i = 0; i < n/2; ++i)
	{
		if(p[i] == 0)
		{
			for(int j = i*2; j < n ; j += i)
			{
				p[j] = 1;
			}
		}
	}
	for(int i = 0, j = 1; i < n && j < 100001; ++i)
	{
		if(p[i] == 0)
		{
			prime[j] = i;
			++j;
		}
	}
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,m, a, b;
		cin>>n>>m;
		
		vector<vector<int> > adj(n);
		
		for(int i = 0; i < m; ++i)
		{
			cin>>a>>b;
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
        
		
		vector<int> tree(n);
		for(int i = 0; i < n; ++i) tree[i] = 0;
		
		int treenum = 1;
		int last=0, maxi = 0, cnt;
		while(last < n)
		{
			for(; (tree[last] !=  0) && (last < n); last++); 
			if(last == n) break;
			
			cnt = DFSAssign(tree, adj, last);
			if(cnt > maxi) maxi = cnt;
		}
		
		if(maxi == 1) cout<<-1<<endl;
		else cout<<prime[maxi]<<endl;
	}
}