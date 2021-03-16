#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n;
	ll sum, temp;
	vector<ll>c, dp;
	
	cin>>n>>sum;
	
	for(int i=0; i<n; i++)
	{	
		cin>>temp;
		c.push_back(temp);
	}
	dp.push_back(1);
	
	for(ll i=1; i<=sum; i++)
	{
		dp.push_back(0);
	}
	
	for(int j=0; j<n; j++)
	{
		for(ll i=1; i<=sum; i++)
		{
			if(c[j] <= i)
			{
				dp[i] += dp[i - c[j]];
				dp[i] %= MOD;
			}
		}
	}
	
	cout<<dp[sum]<<"\n";
	
	return 0;
}
