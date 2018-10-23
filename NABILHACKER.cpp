#include <bits/stdc++.h>

using namespace std;
struct node
{
    char c;
    int next;
    int prev;
    node()
    {
        prev = -1;
        next = -1;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vector<node> nodes;
        int cur=-1, st = -1;

        for(int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            switch(c)
            {
                case '<':
                {
                    if(cur != -1)
                    {
                        cur = nodes[cur].prev;
                    }
                }
                break;
                case '>':
                {
                    if(cur == -1)
                    {
                        if(nodes.size() > 0)
                            cur = st;
                    }
                    else
                    {
                        if(nodes[cur].next != -1)
                            cur = nodes[cur].next;
                    }
                }
                break;
                case '-':
                {
                    if(cur != -1)
                    {
                        nodes[cur].c = '-';
                        int pr = nodes[cur].prev;
                        int ne = nodes[cur].next;
                        if(pr != -1)
                        {
                            nodes[pr].next = ne;
                        }
                        if(ne != -1)
                        {
                            nodes[ne].prev = pr;
                        }
                        if(st == cur)
                        {
                            st = ne;
                        }
                        cur = nodes[cur].prev;
                    }
                }
                break;
                default:
                {
                    node n;
                    n.c = c;
                    if(cur != -1)
                    {
                        n.prev = cur;
                        n.next = nodes[cur].next;
                        int ne = nodes[cur].next;
                        if(ne != -1)
                        {
                            nodes[ne].prev = nodes.size();
                        }
                        nodes[cur].next = nodes.size();
                    }
                    else
                    {
                        if(st != -1)
                        {
                            nodes[st].prev = nodes.size();
                            n.next = st;
                        }
                        st = nodes.size();
                    }
                    cur = nodes.size();
                    nodes.push_back(n);
                }
            }
        }

        while(st != -1 && nodes.size() > st)
        {
            if(nodes[st].c != '-')
                cout<<nodes[st].c;
            
            st = nodes[st].next;
        }
        cout<<endl;
    }
}