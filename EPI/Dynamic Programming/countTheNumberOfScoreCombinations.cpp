#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int maxSumOverSubarrays(vector<int>arr)
{
	int m = INT_MIN;
	vector<int>sum;
	
	sum.push_back(arr[0]);
	
	for(int i=1; i<arr.size(); i++)
	{
		sum.push_back(sum[i-1] + arr[i]);
		
		m = max(m, sum[i]);
		
		if(sum[i] < 0)
			sum[i] = 0;
	}
	
	return m;
}

int main()
{
	int n;
	int arr[] = {2, 3, 7};
	vector<int>dp;
	
	cin>>n;
	
	dp.push_back(1);
	dp.push_back(0);
	
	for(int i=2; i<=n; i++)
	{
		dp.push_back(0);
	}
	
	for(int j=0; j<3; j++)
	{
		for(int i=2; i<=n; i++)
		{
			if(arr[j] <= i)
			{
				dp[i] += dp[i - arr[j]];
			}
		}
	}
	
	cout<<dp[n]<<"\n";
	
	return 0;
}
