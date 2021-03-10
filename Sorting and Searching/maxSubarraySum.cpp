#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n;
	ll temp, max;
	vector<ll>arr, dp;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		arr.push_back(temp);
	}
	
	dp.push_back(arr[0]);
	max = dp[0];
	
	for(int i=1; i<n; i++)
	{
		if(dp[i-1] + arr[i] > arr[i])
			dp.push_back(dp[i-1]+arr[i]);
		else
			dp.push_back(arr[i]);
			
		max = max > dp[i] ? max : dp[i];
	}
	
	cout<<max<<"\n";
	
	return 0;
}
