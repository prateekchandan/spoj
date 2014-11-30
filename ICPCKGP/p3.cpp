#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;

#define fore(i, l, r) for(int i = l; i < r; i++)
#define forn(i, n) fore(i, 0, n)
#define pb push_back
#define mp make_pair
#define x first
#define y second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

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
  int t;
  scanf("%d", &t);
  while(t--){
    char arr1[1005], arr2[1005];
    scanf("%s", arr1);
    scanf("%s", arr2);
    int m;
    scanf("%d", &m);
    int map[26][26];
    char 
    forn()
  }
}
