#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, temp, least, most, profit = 0;
	vector<int>s, dp;
	
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		s.push_back(temp);
	}
	
	least = s[0];
	for(int i=0; i<n; i++)
	{
		if(s[i] < least)
			least = s[i];
		
		profit = max(profit, s[i] - least);
		dp.push_back(profit);
	}
	
	most = s[n-1];
	for(int i=n-1; i>=0; i--)
	{
		if(s[i] > most)
			most = s[i];
			
		profit = max(profit, most - s[i] + dp[i-1]);
	}
	
	cout<<profit<<"\n";
	
	return 0;
}
