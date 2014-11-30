#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
void pnext(string s){
    int l=s.size(),minpos=-1;
    char c;
    for(int i=l-1;i>=1;i--){
		if(s[i-1]<s[i]){
			minpos=i-1;
			break;
		}
    }
    if(minpos==-1){
		cout<<"no answer\n";
		return;
	}
    int maxpos=-1;
    for (int i = minpos; i < l; i++)
	{
		if(s[i]>s[minpos])
		{
			if(maxpos==-1)
				maxpos=i;
			else if(s[i]<s[maxpos])
				maxpos=i;
		}
	}
	c=s[minpos];
	s[minpos]=s[maxpos];
	s[maxpos]=c;
	string::iterator a1=s.begin();
	for (int i = 0; i <= minpos ; i++)
	{
		a1++;
	}
	
	sort(a1,s.end());
    cout<<s<<endl;    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        pnext(s);
    }
    return 0;
}
