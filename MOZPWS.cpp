#include <bits/stdc++.h>

using namespace std;

struct node{
    int st, en;
    long long maxVal;
    
    node()
    {
        maxVal = LLONG_MIN;
        st = INT_MAX;
        en = -1;
    }
};

int nearestPow2(int n)
{
    for(int i = 1; i <= 1000000; i*=2)
    {
        if(n <= i)
        return i;
    }
}

long long findMax(vector<node> &segTree, int nodeIndex, int st, int en)
{
    node n = segTree[nodeIndex];
    if(n.st == st && n.en == en)
    {
        return n.maxVal;
    }

    int l = 2*nodeIndex + 1;
    int r = 2*nodeIndex + 2;

    if(segTree[l].st <= st && segTree[l].en >= en)
        return findMax(segTree, l, st, en);

    if(segTree[r].st <= st && segTree[r].en >= en)
        return findMax(segTree, r, st, en);

    return max(findMax(segTree, l, st, segTree[l].en), findMax(segTree, r, segTree[r].st, en));

}

int main()
{
    int t,n,k,q,x,y;
    cin>>t;

    for(int _it = 1; _it <= t; ++_it)
    {
        cout<<"Case :"<<_it<<endl;
        cin>>n>>k;
        vector<long long> a(n);
        for(int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }

        int treeSize = nearestPow2(n-k+1);
        vector<node> seg(2*treeSize - 1);

        set<long long> mi;
        for(int i = 0; i < k; ++i)
        {
            mi.insert(a[i]);
        }
        for(int i = 0; i <= (n-k); ++i)
        {
            seg[treeSize+i-1].maxVal= *mi.begin();
            seg[treeSize+i-1].st = i;
            seg[treeSize+i-1].en = i;
            mi.erase(a[i]);
            mi.insert(a[i+k]);
        }

        for(int i = 2*treeSize-2; i > 0; i-=2)
        {
            seg[(i-1)/2].maxVal = max(seg[i].maxVal, seg[i-1].maxVal);
            seg[(i-1)/2].st = min(seg[i].st, seg[i-1].st);
            seg[(i-1)/2].en = max(seg[i].en, seg[i-1].en);
        }

        cin>>q;
        /*
        for(int i = 0; i < 2*treeSize -1; ++i)
        {
            cout<<seg[i].maxVal<<" "<<seg[i].st<<" "<<seg[i].en<<endl;
        }*/

        while(q--)
        {
            cin>>x>>y;
            x--;
            y--;
            y = y - k + 1;
            if(y>=x)
            cout<<findMax(seg, 0, x, y)<<endl;
            else
            cout<<"Impossible\n";
        }
    }
}