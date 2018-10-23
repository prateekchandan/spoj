#include <bits/stdc++.h>
using namespace std;

struct node{
    int st, en;
    long long mCount, sCount, postSCount, preSCount;
    long long ans;
    
    node()
    {
        st = INT_MAX;
        en = -1;
        mCount = 0;
        sCount = 0;
        postSCount = 0;
        preSCount = 0;
        ans = 0;
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

node findAns(vector<node> &segTree, int nodeIndex, int st, int en)
{
    //cout<<"* "<<nodeIndex<<" "<<st<<" "<<en<<endl;
    node n = segTree[nodeIndex];
    if(n.st == st && n.en == en)
    {
        return n;
    }

    int l = 2*nodeIndex + 1;
    int r = 2*nodeIndex + 2;

    if(segTree[l].st <= st && segTree[l].en >= en)
        return findAns(segTree, l, st, en);

    if(segTree[r].st <= st && segTree[r].en >= en)
        return findAns(segTree, r, st, en);

    node ln = findAns(segTree, l, st, segTree[l].en);
    node rn = findAns(segTree, r, segTree[r].st, en);

    node p;
    p.mCount = ln.mCount + rn.mCount;
    p.sCount = ln.sCount + rn.sCount;
    p.postSCount = ln.postSCount + rn.postSCount + ln.mCount * rn.sCount;
    p.preSCount = ln.preSCount + rn.preSCount + rn.mCount * ln.sCount;
    p.ans = ln.ans + rn.ans + ln.preSCount * rn.sCount + rn.postSCount * ln.sCount;
    return p;

}

int main()
{
    string s;
    cin>>s;
    int n = s.size();
    int nLeaf = nearestPow2(n);
    vector<node> seg(2 * nLeaf - 1);

    for(int i = 0; i < n; ++i)
    {
        node &nd = seg[nLeaf - 1 + i];
        if(s[i] == 's')
        nd.sCount = 1;
        else if(s[i] == 'm')
        nd.mCount = 1;
        nd.st = i;
        nd.en = i;
    }
    for(int i = 2 * nLeaf - 2; i > 0; i -= 2)
    {
        node &r = seg[i];
        node &l = seg[i-1];
        node &p = seg[(i-1)/2];

        p.mCount = l.mCount + r.mCount;
        p.sCount = l.sCount + r.sCount;
        p.postSCount = l.postSCount + r.postSCount + l.mCount * r.sCount;
        p.preSCount = l.preSCount + r.preSCount + r.mCount * l.sCount;
        p.ans = l.ans + r.ans + l.preSCount * r.sCount + r.postSCount * l.sCount;

        p.st = min(l.st, r.st);
        p.en = max(l.en, r.en);
    }

    /*cout<<"SEGTREE : \n";
    for(int i = 0; i < 2*nLeaf - 1; ++i)
    {
        cout<<i<<": "<<seg[i].ans<<" - "<<seg[i].st<<","<<seg[i].en<<" : "<<seg[i].ans<<endl;
    }*/
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--; r--;
        cout<<findAns(seg, 0, l , r).ans<<endl;
    }
}