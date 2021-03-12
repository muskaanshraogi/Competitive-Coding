#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, start = 1, ans = 0;
	ll temp;
	map<ll, ll>lastIdx;

	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		cin>>temp;
		
		start = start > lastIdx[temp] ? start : lastIdx[temp] + 1;
		ans = ans > i-start+1 ? ans : i - start + 1;
		
		lastIdx[temp] = i;
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
