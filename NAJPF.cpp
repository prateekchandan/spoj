#include <iostream>
#include <vector>
#include <string>
using namespace std;
void calcs(string const &p ,  vector<int> &s)
{
	s[0]=0;
	int l=p.size();
	for(int i=1;i<l;i++)
	{
		int k=s[i-1];
		while(1){
			if(p[k]==p[i])
			{
				s[i]=k+1;
				break;
			}
			else if(k==0)
			{
				s[i]=0;
				break;
			}
			else
			{
				k=s[k-1];
			}
		}
	}
}
void calcf(string const &p ,  vector<int> &f,vector <int> const &s)
{
	
	f[0]=-1;
	int l=p.size();
	for(int i=1;i<l;i++)
	{
		int k=s[i-1];
		while(1){
			if(p[k]!=p[i])
			{
				f[i]=k;
				break;
			}
			else if(k==0)
			{
				f[i]=-1;
				break;
			}
			else
			{
				k=s[k-1];
			}
		}
	}
}
void count(string const &main,string const &ch) 
{
	int c=0,l1=main.length(),l2=ch.length(),j=0;
	vector <int> f(l2);
	vector <int> s(l2);
	calcs(ch,s);
	calcf(ch,f,s);
	vector<int> pos;
	
	cout<<endl;
	int st=0;
	for(int i=0;i<l1;)
	{
		if(ch[j]==main[i]&&j==l2-1)
		{
			j=s[j];
			pos.push_back(st);
			i++;
			c++;
			st=i-j;
		}
		else if(ch[j]==main[i])
		{
			i++;
			j++;
		}
		else
		{
			j=f[j];
			if(j==-1)
			{
				j=0;
				i++;
			}
			st=i-j;
		}
	}
	if(c==0)
		cout<<"Not Found\n";

	else
	{
		cout<<c<<endl;
		for (int i = 0; i < pos.size(); ++i)
		{
			cout<<pos[i]+1<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int main()
{
	string s,s1;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s>>s1;
		count(s,s1);
	}
	return 0;
}
