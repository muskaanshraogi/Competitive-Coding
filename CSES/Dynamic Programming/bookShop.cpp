#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int compare(pair<int, int>&x, pair<int, int>&y)
{
	return x.first < y.first;
}	

int main()
{
	int n, x, temp;
	vector<int>price, dp[1001];
	vector<pair<int, int>>b;
	
	cin>>n>>x;
	
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		price.push_back(temp);
	}
	
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		b.push_back(make_pair(price[i], temp));
		dp[i].push_back(0);
	}
	sort(b.begin(), b.end(), compare);
	
	for(int i=0; i<n; i++)
	{
		for(int j=1; j<=x; j++)
		{
			dp[i].push_back(0);
			
			if(!i)
			{
				if(b[i].first <= j)
					dp[i][j] = b[i].second;
			}
			else
			{
				dp[i][j] = dp[i-1][j];
				
				if(j >= b[i].first)
					dp[i][j] = max(dp[i][j], b[i].second +dp[i-1][j-b[i].first]);
			}
		}
	}
	
	cout<<dp[n-1][x]<<"\n";
	
	return 0;
}
