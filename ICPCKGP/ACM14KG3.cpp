#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define Size 26
#define fore(i, l, r) for(int i = l; i < r; i++)
#define forn(i, n) fore(i, 0, n)
using namespace std;
void dfs(int G[26][26], int idx, int visited[]){
  visited[idx] = 1;
  forn(i, 26){
    if(G[idx][i] && !visited[i]) dfs(G, i, visited);
  }
}

void compose(int a[26][26]){
  int b[26][26];
  forn(i, 26){
    forn(j, 26) b[i][j] = 0;
  }
  
  forn(i, 26){
    dfs(a, i, b[i]);
  }
  
  forn(i, 26){
    forn(j, 26) a[i][j] = b[i][j];
  }
}

int main(){
	std::ios_base::sync_with_stdio(false);
	int t,m,x,y,s1,s2;
	cin>>t;
	string a,b,temp;
	int r[Size][Size];
	while(t--){
		cin>>a>>b;
		cin>>m;
		for (int i = 0; i < Size; i++)
		{
			for (int j = 0; j < Size; j++)
			{
				r[i][j]=0;
			}
			
		}
		
		for (int i = 0; i < m; i++)
		{
			cin>>temp;
			x = temp[0] - 'a';
			y = temp[3] - 'a';
			r[x][y]=1;
		}
		compose(r);
		
		s1 = a.size();
		s2 = b.size();
		if(s1!=s2)
		{
			cout<<"NO"<<endl;
			continue;
		}
		int flag=0;
		for (int i = 0; i < s1; i++)
		{
			x = a[i] - 'a';
			y = b[i] - 'a';
			if(a[i]!=b[i] && r[x][y]==0){
				cout<<"NO"<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0)
		cout<<"YES"<<endl;
		
		
	}
	return 0;
}


