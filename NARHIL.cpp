#include <bits/stdc++.h>
using namespace std;

// An AVL tree node 
struct Node 
{ 
    long long key; 
    struct Node *left; 
    struct Node *right; 
    int height; 
    int count;
    long long sum;
}; 
  
// A utility function to get the height of the tree 
int height(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 

// A utility function to get the count of the tree 
int count(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->count; 
} 

// A utility function to get the sum of the tree 
int sum(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->sum; 
} 
  
/* Helper function that allocates a new node with the given key and 
    NULL left and right pointers. */
Node* newNode(long long key) 
{ 
    Node* node = new Node; 
    node->key   = key; 
    node->sum   = key; 
    node->count  = 1; 
    node->left   = NULL; 
    node->right  = NULL; 
    node->height = 1;  // new node is initially added at leaf 
    return(node); 
} 
  
// A utility function to right rotate subtree rooted with y 
// See the diagram given above. 
Node *rightRotate(struct Node *y) 
{ 
    Node *x = y->left; 
    Node *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 

    // Update count 
    y->count = count(y->left) + count(y->right) + 1; 
    x->count = count(x->left) + count(x->right) + 1; 

    // Update sum 
    y->sum = sum(y->left) + sum(y->right) + y->key; 
    x->sum = sum(x->left) + sum(x->right) + x->key; 
  
    // Return new root 
    return x; 
} 
  
// A utility function to left rotate subtree rooted with x 
// See the diagram given above. 
Node *leftRotate(struct Node *x) 
{ 
    Node *y = x->right; 
    Node *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 

    // Update count 
    x->count = count(x->left) + count(x->right) + 1; 
    y->count = count(y->left) + count(y->right) + 1; 

    // Update sum 
    x->sum = sum(x->left) + sum(x->right) + x->key; 
    y->sum = sum(y->left) + sum(y->right) + y->key; 
  
    // Return new root 
    return y; 
} 
  
// Get Balance factor of node N 
int getBalance(Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 
  
// Recursive function to insert a key in the subtree rooted 
// with node and returns the new root of the subtree. 
pair<Node*, long long> insert(Node* node, int key) 
{ 
    /* 1.  Perform the normal BST insertion */
    if (node == NULL) 
        return(make_pair<Node*, long long>(newNode(key), 0)); 
  
    pair<Node*, long long> retVal;
    long long diff;
    if (key < node->key)
    {
        retVal  = insert(node->left, key); 
        node->left  = retVal.first; 
        diff = retVal.second;
        diff += (sum(node->right) + node->key) - (key * (count(node->right) + 1));
    }
    else
    {
        retVal  = insert(node->right, key); 
        node->right  = retVal.first; 
        diff = retVal.second;
    }
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), 
                           height(node->right)); 

    node->count = count(node->left) + count(node->right) + 1;
    node->sum = sum(node->left) + sum(node->right) + node->key;
  
    /* 3. Get the balance factor of this ancestor 
          node to check whether this node became 
          unbalanced */
    int balance = getBalance(node); 
  
    // If this node becomes unbalanced, then 
    // there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && key < node->left->key) 
        return make_pair<Node*, long long>(rightRotate(node), diff); 
  
    // Right Right Case 
    if (balance < -1 && key > node->right->key) 
        return make_pair<Node*, long long>(leftRotate(node), diff); 
  
    // Left Right Case 
    if (balance > 1 && key > node->left->key) 
    { 
        node->left =  leftRotate(node->left); 
        return make_pair<Node*, long long>(rightRotate(node), diff); 
    } 
  
    // Right Left Case 
    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate(node->right); 
        return make_pair<Node*, long long>(leftRotate(node), diff); 
    } 
  
    /* return the (unchanged) node pointer */
    return make_pair<Node*, long long>(node, diff); 
} 

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n), h(n);

        for(int i = 0; i < n ; ++i)
        {
            cin>>a[i];
        }

        for(int i = 0; i < n ; ++i)
        {
            cin>>h[i];
        }

        int moreFound = false;
        for(int i =0; i < n-1; ++i)
        {
            if(h[i] >= h[n-1])
            {
                moreFound = true;
                break;
            }
        }

        if(!moreFound)
        {
            cout<<-1<<endl;
            continue;
        }

        Node* root = NULL;
        vector<long long> sm(n, 0), minCost(n-1, LLONG_MAX);
        for(int i = n-2; i >=0; --i)
        {
            //cout<<i<<endl;
            pair<Node*, long long> ret = insert(root, h[i]);
            root = ret.first;
            sm[i] = ret.second;
        }
        long long minC = LLONG_MAX;
        for(int i = 0; i < n-1; ++i)
        {
            minCost[i] = sm[i] + 2 * abs(a[i] - a[0]);
            if(minCost[i] < minC)
                minC = minCost[i];
        }

        cout<<minC<<endl;

    }
}

