#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, start;
	char c;
	vector<char>s;
	vector<int>dp;
	unordered_map<char, int>table;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>c;
		s.push_back(c);
	}
	
	start = 0;
	dp.push_back(1);
	table[s[0]] = 0;
	
	for(int i=1; i<n; i++)
	{
		if(table.find(s[i]) != table.end() && table[s[i]] >= start)
		{
			start = table[s[i]] + 1;
		}
		
		dp.push_back(max(dp[i-1], i - start + 1));
		table[s[i]] = i;
	}
	
	cout<<dp[n-1]<<"\n";
	
	return 0;
}
