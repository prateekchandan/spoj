#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

#define SIZE 1000001
int main(){
	int n;

	vector<int> win(SIZE,0);

	win[1] = 1;
	int ans , k;

	for (int i = 2; i < SIZE; ++i)
	{
		ans = 0;
		k = sqrt(i);

		for (int j = k; j > 0 ; --j)
		{
			if(win[i - (j*j)] == 0)
			{
				ans = 1;
				break;
			}
		}
		win[i] = ans;
	}

	cin>>n;

	while(n--)
	{
		cin>>k;
		if(win[k] == 0)
			cout<<"Lose\n";
		else
			cout<<"Win\n";
	}


	return 0;
}