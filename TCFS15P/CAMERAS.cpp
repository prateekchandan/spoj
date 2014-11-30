#include <bits/stdc++.h>
using namespace std;
struct node{
	node *left;
	node *right;
	int disable,Min,Max;
	int leaf;
	int count;
	node(){
		left=NULL; right=NULL;
		disable=0;
		Min=0 ; Max=0;
		leaf=0;
		count=0;
	}
};
node* createTree(int n,vector<int> &a,int st,int en){
	int t1=n/2;
	int t2=n-t1;
	node* root=new node;
	if(n==1){
		root->Min=a[st];
		root->Max=a[st];
		root->leaf=1;
		root->count=1;
		return root;
	}
	root->left = createTree(t1,a,st,st+t1-1);
	root->right = createTree(t2,a,st+t1,en);
	root->count=root->left->count+root->right->count;
	root->Min=a[st];
	root->Max=a[en];
	return root;
	
}
void disable(node *root,int &a,int &b){
	if(root->Min > b)
		return;
	if(root->Max < a)
		return;
	
	if(root->Min >= a && root->Max <= b){
		root->disable=1;
		return;
 	}
 	
 	disable(root->left,a,b);
 	disable(root->right,a,b);
}

int dfs(node* root){
	if(root==NULL)
	return 0;
	
	if(root->disable==1)
		return root->count;
	
	return dfs(root->left) + dfs(root->right);
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	node *root=createTree(n,a,0,n-1);
	int x,b;
	for (int i = 0; i < k; i++)
	{
		cin>>x>>b;
		disable(root,x,b);
	}
	
	cout<<dfs(root);
	return 0;
}
