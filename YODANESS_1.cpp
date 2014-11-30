// PRATEEK CHANDAN
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std; 
// An AVL tree node
long long maincount=0;
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int count;
    int height;
};
 
// A utility function to get maximum of two integers
int max(int a, int b);
 
// A utility function to get height of the tree
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}


// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct node* newNode(int key)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    node->count =1; // It stores no of nodes in the tree
    return(node);
}
 
// A utility function to right rotate subtree rooted with y
// See the diagram given above.
int givecount(node* t)
{
	if(t==NULL)
	return 0;
	else
	return t->count;
}
void updatecount(node *&t)
{
	if(t==NULL)
	return;
	
	else
	t->count=1+givecount(t->left)+givecount(t->right);
}
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    //UPDTAE COUNT
    updatecount(y);
    updatecount(x);
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    // UPDATE COUNT
    updatecount(x);
    updatecount(y);
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
struct node* insert(struct node* node, int key)
{
    /* 1.  Perform the normal BST rotation */
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        {
			maincount+= givecount(node->right)+1;
			node->left  = insert(node->left, key);
		}
    else
        node->right = insert(node->right, key);
 
    /* 2. Update height of this ancestor node */
    node->height = max(height(node->left), height(node->right)) + 1;
 
	updatecount(node);
    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
 

 

/* Drier program to test above function*/
int main()
{
	int t,a,n;
	string x;
	cin>>t;
	while(t--)
	{
		maincount=0;
		scanf("%d",&n);
		struct node *root = NULL;
		tr1::unordered_map<string,int> y;
		for (int i = 0; i < n; i++)
		{
			cin>>x;
			y[x]=i;
		}
		
		for (int i = 0; i < n; i++)
		{
			cin>>x;
			a=y[x];
			root=insert(root,a);
			//cout<<z[i]<<" : "  ;
		}	
		cout<<maincount<<endl;
	}
    return 0;
}


