#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main()
{
	long long l, ans;

	cin>>l;
	
	ans = 1;
	while(l--)
	{
		ans = (ans*2) % MOD;
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
