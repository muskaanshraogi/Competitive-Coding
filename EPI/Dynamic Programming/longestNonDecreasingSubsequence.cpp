#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, temp, m = 0;
	vector<int>arr, dp;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		arr.push_back(temp);
	}
	
	dp.push_back(1);
	
	for(int i=1; i<n; i++)
	{
		dp.push_back(0);
		
		for(int j=0; j<i; j++)
		{
			if(arr[i] >= arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
				m = max(dp[i], m);
			}
		}
	}
	
	cout<<m<<"\n";
	
	return 0;
}
