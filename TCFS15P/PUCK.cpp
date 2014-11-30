#include <bits/stdc++.h>
#define even(n) n%2==0
#define odd(n) n%2==1
using namespace std;
struct node{
	node *left;
	node *right;
	int even,odd,Min,Max;
	long long count;
	int op,opid;
	node(){
		left=NULL; right=NULL;
		even=0; odd=0; 
		count=0;
		op=0; opid=0;
		Min=0;
		Max=0;
	}
};
node* createTree(int n,vector<int> &a,int st,int en){
	int t1=n/2;
	int t2=n-t1;
	node* root=new node;
	root->Min=st;
	root->Max=en;

	if(n==1){
		if(even(a[st]))
			root->even=1;
		else
			root->odd=1;
		
		root->count=a[st];
		return root;
	}
	root->left = createTree(t1,a,st,st+t1-1);
	root->right = createTree(t2,a,st+t1,en);
	root->count=root->left->count+root->right->count;
	root->even=root->left->even+root->right->even;
	root->odd=root->left->odd+root->right->odd;
	return root;
}
void makechange(node* root,int op){
	//cout<<op<<" **\n";
	if(op==1){
		root->count += root->odd;
		root->even += root->odd;
		root->odd=0;
	}
	if(op==2){
		root->count += root->even;
		root->odd += root->even;
		root->even=0;
	}
	if(op==3){
		root->count += root->odd + root->even;
		root->even += root->odd;
		root->odd=root->even-root->odd;
		root->even=root->even-root->odd;
	}
}
// op = 1 means all even
// op = 2 means all odd
// op = 3 means alter
void applyop(node *root,int &a,int &b,int &op,int&opid,vector<pair<int,int> > listop){
	if(root->Min > b)
		return;
	if(root->Max < a)
		return;
	
	if(root->Min >= a && root->Max <= b){
		int l=listop.size();
		int cuid=root->opid;
		for (int i = 0; i < l; i++)
		{
			if(listop[i].second > cuid)
			{
				makechange(root,listop[i].first);
			}
		}
		makechange(root,op);
		root->op=op;
		root->opid=opid;
		return;
 	}
 	if(root->op!=0){
		pair<int,int> temp;
		temp.first=root->op;
		temp.second=root->opid;
		listop.push_back(temp);
	}
 	applyop(root->left,a,b,op,opid,listop);
 	applyop(root->right,a,b,op,opid,listop);
 	root->count=root->left->count+root->right->count;
	root->even=root->left->even+root->right->even;
	root->odd=root->left->odd+root->right->odd;
	//root->opid=opid;
}

int counttotal(node *root,int &a,int &b){
	if(root->Min > b)
		return 0;
	if(root->Max < a)
		return 0;
	
	if(root->Min >= a && root->Max <= b){
		return root->count;
 	}
 	
 	return counttotal(root->left,a,b) +  counttotal(root->right,a,b);
}

void print(node * root){
	if(root->left==NULL){
		cout<<root->count<<" : "<<root->even<<" : "<<root->odd<<" * \n";
	}
	else{
		print(root->left);
		cout<<root->count<<" : "<<root->even<<" : "<<root->odd<<" & \n";
		print(root->right);
		
	}
}

int main(){
	int n,k;
	cin>>n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	node *root=createTree(n,a,0,n-1);
	
	cin>>k;
	int x,y,op,opid;
	char c;
	for (int i = 0; i < k; i++)
	{
		op=0;
		cin>>c>>x>>y;
		x--; y--;
		opid=i+1;
		vector<pair<int,int> > temp;
		if(c=='M')
		{
			applyop(root,x,y,op,opid,temp);
			cout<<counttotal(root,x,y)<<endl;
			continue;
		}
		if(c=='E')
			op=1;
		else if(c=='O')
			op=2;
		else if(c=='I')
			op=3;
	
		applyop(root,x,y,op,opid,temp);
	}
	
	/*cout<<"========================================================\n";
	print(root);
	cout<<"========================================================\n";*/
	
	return 0;
}

