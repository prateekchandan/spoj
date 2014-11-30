#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int l1,l2,a1[26],count1,i,j;
void ispresent(char a[],char b[])
{
	l1=strlen(a);
	l2=strlen(b);
	
	if(l2>l1)
	{
		printf("NO\n");
		return;
	}
	count1=0;
	for (i = 0; i < 26; i++)
	{	
		a1[i]=0;
	}
	
	for (i = 0; i < l2; i++)
	{
		if(a1[b[i]-97]==0)
			count1++;
		
		a1[b[i]-97]--;
	}
	for (j = 0; j < l2; j++)
	{	
		a1[a[j]-97]++;
		
		if(a1[a[j]-97]==0)
			count1--;
	}
	for (i = 1; j < l1 ; i++,j++)
	{
		if(count1==0){
			printf("YES\n");
			return;
		}
		
		if(a1[a[i-1]-97]==0)
			count1++;
			
		a1[a[j]-97]++;
		a1[a[i-1]-97]--;
		
		if(a1[a[j]-97]==0)
			count1--;
	}
	
	if(count1==0)
		printf("YES\n");
	else
		printf("NO\n");
		return;
	
}
int main(){
	int t;
	scanf("%d",&t);
	char s1[1000000],s2[1000000];
	while(t--){
		scanf("%s",s1);
		scanf("%s",s2);
		ispresent(s1,s2);
	}
	return 0;
}
