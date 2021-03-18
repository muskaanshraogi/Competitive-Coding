#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n;
	char g;
	vector<ll>dp[1001];
	
	cin>>n;
	
	dp[0].push_back(1);
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i || j)
				dp[i].push_back(0);
			
			cin>>g;
			
			if(g == '.')
			{
				if(i > 0)
				{
					dp[i][j] += dp[i-1][j];
				}
				if(j > 0)
				{
					dp[i][j] += dp[i][j-1];
				}
				
				dp[i][j] %= MOD;
			}
			else
			{
				dp[i][j] = 0;
			}
		}
	}
	
	cout<<dp[n-1][n-1]<<"\n";
	
	return 0;
}
