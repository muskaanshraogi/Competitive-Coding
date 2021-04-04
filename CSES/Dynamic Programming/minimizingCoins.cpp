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
	
	dp.push_back(0);
	
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		c.push_back(temp);
	}
	
	for(int i=1; i<=sum; i++)
	{
		dp.push_back(INT_MAX);
		
		for(int j=0; j<c.size(); j++)
		{
			if(c[j] <= i)
			{
				dp[i] = min(dp[i], dp[i-c[j]] + 1);
			}
		}
	}
	
	if(dp[sum] == INT_MAX)
		cout<<"-1\n";
	else
		cout<<dp[sum]<<"\n";
	
	return 0;
}
