#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, num, idx = 0;
	vector<int>dp;
	vector<vector<int>>triangle;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		vector<int>temp;
		
		for(int j=0; j<i+1; j++)
		{
			cin>>num;
			temp.push_back(num);
		}
		
		triangle.push_back(temp);
	}
	
	dp.push_back(triangle[0][0]);
	
	for(int i=1; i<n; i++)
	{
		if(dp[i-1] + triangle[i][idx] < dp[i-1] + triangle[i][idx+1])
		{
			dp.push_back(dp[i-1] + triangle[i][idx]);
		}
		else
		{
			dp.push_back(dp[i-1] + triangle[i][idx+1]);
			idx++;
		}
	}
	
	cout<<dp[n-1]<<"\n";
	
	return 0;
}
