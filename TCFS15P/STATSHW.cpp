#include <bits/stdc++.h>

using namespace std;
// An AVL tree node
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
    int count;
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

int n_count(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->count;
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
    node->count = 1;
    return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
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
    
    // Update counts
    y->count = n_count(y->left)+ n_count(y->right)+1;
    x->count = n_count(x->left)+ n_count(x->right)+1;
   

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
	
	// Update counts
    x->count = n_count(x->left)+ n_count(x->right)+1;
    y->count = n_count(y->left)+ n_count(y->right)+1;
    
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
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* 2. Update height & count of this ancestor node */
    
    node->height = max(height(node->left), height(node->right)) + 1;
	
	node->count  = n_count(node->left) + n_count(node->right) + 1;
    
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

/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root, int key)
{
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct node *temp = root->left ? root->left : root->right;

            // No child case
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of the non-empty child

          
        }
        else
        {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            struct node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = max(height(root->left), height(root->right)) + 1;
    root->count = n_count(root->left)+ n_count(root->right) + 1;

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
    //  this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void preOrder(struct node *root)
{
    if(root != NULL)
    {
        cout<<root->key <<" : "<<root->count<<endl;
        
        cout<<"l\n";
        preOrder(root->left);
        cout<<"r\n";
        preOrder(root->right);
    }
}

int find_n(struct node *root,int n){
	if(root==NULL){
		return -1;
	}
	else if(n_count(root->left) + 1 == n)
		return root->key;
	
	if(n <= n_count(root->left))
		return find_n(root->left,n);
	
	return find_n(root->right,n-(1+ n_count(root->left)));
	
}

struct heap{
	int val;
	int fre,index;
	heap(){
		val=0; fre=1; index=-1;
	}
};


bool lesshp(heap* a,heap* b){
	if(a->fre==b->fre){
		return a->val<b->val;
	}
	return a->fre<b->fre;
}

void insert_heap(vector<heap*> &a,heap *b){
	int l=a.size(),n;
	b->index=l;
	a.push_back(b);
	heap* temp;
	while(l>0){
		n=l;
		l=(l-1)/2;
		if(l< 0)
		break;
		if(lesshp(a[l],a[n]))
		{
			temp=a[n];
			a[n]=a[l];
			a[l]=temp;
			a[l]->index=l;
			a[n]->index=n;
		}
		else
		break;
	}
}

void update_heap_inc(vector<heap*> &a,int l){
	int n;
	heap* temp;
	while(l>0){
		n=l;
		l=(l-1)/2;
		if(lesshp(a[l],a[n]))
		{
			temp=a[n];
			a[n]=a[l];
			a[l]=temp;
			a[l]->index=l;
			a[n]->index=n;
		}
		else
		break;
	}
}

void update_heap_dec(vector<heap*> &a,int in){
	int n1,n2,l,n;
	l=a.size();
	heap* temp;
	while(in<l){
		n1 = 2 * in +1;
		n2 = 2 * in +2;
		if(n2 >=l && n1>=l)
			break;
		else if(n2>=l && lesshp(a[n1],a[in]))
			break;
		else if(n2>=l)
		{
			temp=a[n1];
			a[n1]=a[in];
			a[in]=temp;
			a[in]->index=in;
			a[n1]->index=n1;
			in=n1;
		}
		else
		{
			if(lesshp(a[n1],a[in]) && lesshp(a[n2],a[in]))
				break;
			else if(lesshp(a[n2],a[in]))
			{
				temp=a[n1];
				a[n1]=a[in];
				a[in]=temp;
				a[in]->index=in;
				a[n1]->index=n1;
				in=n1;
			}
			else if(lesshp(a[n1],a[in]))
			{
				temp=a[n2];
				a[n2]=a[in];
				a[in]=temp;
				a[in]->index=in;
				a[n2]->index=n2;
				in=n2;
			}
			else if(lesshp(a[n2],a[n1]))
			{
				temp=a[n1];
				a[n1]=a[in];
				a[in]=temp;
				a[in]->index=in;
				a[n1]->index=n1;
				in=n1;
			}
			else{
				temp=a[n2];
				a[n2]=a[in];
				a[in]=temp;
				a[in]->index=in;
				a[n2]->index=n2;
				in=n2;
			}
		}
	}
}


int main(){
	
	int n,q,pos,val,pre,median,midpos;
	long double mean=0,res=0;
	cin>>n>>q;
	
	vector<heap*> heap_v;
	map<int,heap*> heap_m;
	map<int,heap*>::iterator heap_it;
	heap* h_temp;
	midpos=n/2+1;
	
	vector<int> a(n);
	
	
	struct node *medroot = NULL;
	
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
		medroot=insert(medroot,a[i]);
		res+=a[i];
		if(i%1000 == 0)
		{
			mean+=res/n;
			res=0;
		}
		heap_it=heap_m.find(a[i]);
		if(heap_it!=heap_m.end()){
			h_temp=heap_it->second;
			h_temp->fre++;
			update_heap_inc(heap_v,h_temp->index);
		}
		else{
			h_temp=new heap;
			h_temp->val=a[i];
			insert_heap(heap_v,h_temp);
			heap_m[a[i]]=h_temp;
		}
		
	}
	mean+=res/n;
	
	
	cout << fixed;
	for (int i = 0; i < q; i++)
	{
		
		
		cin>>pos>>val;
		pre=a[pos];
		
		a[pos]=val;
		
		mean=(mean - (long double)pre/n )+ (long double)val/n;
		
		medroot=insert(medroot,val);
		//preOrder(medroot);
		medroot=deleteNode(medroot,pre);
		
		
		median=find_n(medroot,midpos);
		
		//////////////////////////////////////////// HEAP UPDATE FOR NEW
		
		heap_it=heap_m.find(val);
		if(heap_it!=heap_m.end()){
			h_temp=heap_it->second;
			h_temp->fre++;
			update_heap_inc(heap_v,h_temp->index);
		}
		else{
			h_temp=new heap;
			h_temp->val=val;
			insert_heap(heap_v,h_temp);
			heap_m[val]=h_temp;
		}
		
		
		/////////////////////////////////////////////// HEAP UPDATE FOR OLD
		
		heap_it=heap_m.find(pre);
		if(heap_it!=heap_m.end()){
			h_temp=heap_it->second;
			h_temp->fre--;
			update_heap_dec(heap_v,h_temp->index);
		}
		
		
		////////////////////////////////////////////////
		cout<<mean<<" "<<median<<" "<<heap_v[0]->val<<endl;
		
	}
	
	
	return 0;
}
