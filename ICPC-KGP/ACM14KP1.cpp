#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <iomanip>
using namespace std;

struct point{
	long double x;
	long double y;
	point(){
		x=0.0;
		y=0.0;
	}
};

long double  distance(long double x,long double y,long double x1 ,long double y1){
	return (sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1)));
}


bool operator<(point a,point b){
	if(a.x == b.x)
	{
		return a.y<b.y;
	}
	else
		return a.x<b.x;
}

bool sorty(point a, point b){
	if(a.y == b.y)
	{
		return a.x<b.x;
	}
	else
		return a.y<b.y;
}

long double minperi(vector<point> p,int st,int en)
{
	
	if(st>=en)
		return INT_MAX;
	
	int mid=(st+en)/2,xmin,xmax;
	long double minans,ans1,ans2;
	
	ans1=minperi(p,st,mid-1);
	ans2=minperi(p,mid+1,en);
	minans=((ans1<ans2)?ans1:ans2);
	
	for (xmax = mid; xmax<= en ; xmax++)
	{
		if(p[xmax].x>p[mid].x+minans)
			break;
	}
	for (xmin = mid; xmin >=0  ; xmin--)
	{
		if(p[xmin].x<p[mid].x-minans)
			break;
	}
	
	vector<point> tp(xmax - xmin +1);
	for (int i = xmin; i <= xmax ; i++)
	{
		tp[i-xmin]=p[i];
	}
	
	sort(tp.begin(),tp.end(),sorty);
	
	int l=tp.size();
	long double temp;
	
	long double mincat=minans;
	 
	for (int i = 0; i < l; i++)
	{
		for (int j = i+1; j < l; j++)
		{
			for (int k = j+1; k < l; k++)
			{
				if(abs( tp[i].y - tp[k].y ) > minans)
					break;
					
				temp=distance(tp[i].x,tp[i].y,tp[j].x,tp[j].y) + distance(tp[j].x,tp[j].y,tp[k].x,tp[k].y) + distance(tp[i].x,tp[i].y,tp[k].x,tp[k].y);
				
				if(temp<mincat)
					mincat=temp;
				
			}
			if(abs(tp[i].y-tp[j].y)>minans)
				break;
		}
		
	}
	
	return mincat;
	
}
int main(){
	int t,n;
	long double ans;
	cin>>t;
	cout<<fixed<<setprecision(8);
	for (int iter = 1; iter <= t ; iter++)
	{
		cin>>n;
		vector<point> a(n);
		for (int i = 0; i < n; i++)
		{
			cin>>a[i].x>>a[i].y;
		}
		sort(a.begin(),a.end());
		
		ans=minperi(a,0,n-1);
		if(ans==INT_MAX)
			ans=0;
		cout<<"Case "<<iter<<": "<<ans<<endl;
		
	}
	
	return 0;
}

