#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int t, num = 0;
	
	cin>>t;
	
	while(t)
	{
		num += t & 1;
		t >>= 1;
	}
	
	cout<<num<<"\n";
	
	return 0;
}
