#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, w, v, k;
	vector<vector<int>>dp;
	vector<pair<int, int>>arr;
	
	cin>>n>>k;
	
	for(int i=0; i<n; i++)
	{
		cin>>w>>v;
		arr.push_back({w, v});
	}
	
	for(int i=0; i<=n; i++)
	{
		vector<int>temp;
		
		for(int j=0; j<=k; j++)
		{
			temp.push_back(0);
		}
		dp.push_back(temp);
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=k; j++)
		{
			if(arr[i-1].first <= j)
			{
				dp[i][j] = max(dp[i-1][j], arr[i-1].second + dp[i-1][j - arr[i-1].first]);
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	cout<<dp[n][k]<<"\n";
	
	return 0;
}
