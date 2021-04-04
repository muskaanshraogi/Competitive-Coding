#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	long long n;
	vector<long long>dp;
	
	cin>>n;
	
	dp.push_back(1);
	
	for(int i=1; i<=n; i++)
	{
		dp.push_back(0);
		
		for(int j=1; j<=6; j++)
		{
			if(i - j >= 0)
				dp[i] += dp[i-j];
		}
		
		dp[i] %= MOD;
	}
	
	cout<<dp[n]<<"\n";
	
	return 0;
}
