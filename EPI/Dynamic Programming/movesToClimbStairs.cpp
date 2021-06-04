#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, k;
	vector<int>dp;
	
	cin>>n>>k;
	
	dp.push_back(1);
	
	for(int i=1; i<=n; i++)
	{
		dp.push_back(0);
		
		dp[i] += dp[i-1];
		
		if(k <= i)
		{
			dp[i] += dp[i-k];
		}
	}
	
	cout<<dp[n]<<"\n";
	
	return 0;
}
