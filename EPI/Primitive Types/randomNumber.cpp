#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int l, u, num, range;
	
	cin>>l>>u;
	range = u - l + 1;
	
	do
	{
		srand(time(NULL));
		num = 0;
		for(int i=0; i<(int)log2(range)+1; i++)
		{
			num = (num << 1) | (rand() & 1);
		} 
	}
	while(num >= range);
	
	cout<<num + l<<"\n";
	
	return 0;
}
