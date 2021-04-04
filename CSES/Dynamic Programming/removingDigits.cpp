#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	ll t;
	vector<ll>dp;
	
	cin>>t;
	
	dp.push_back(0);
	
	for(ll i=1; i<=t; i++)
	{
		dp.push_back(INT_MAX);
		
		for(char c: to_string(i))
		{
			dp[i] = dp[i] < dp[i-(c-'0')] + 1 ? dp[i] : dp[i-(c-'0')] + 1;
		}
	}
	
	cout<<dp[t]<<"\n";
	
	return 0;
}
