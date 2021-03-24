#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	string s1, s2;
	vector<ll>dp[5001];
	
	cin>>s1>>s2;
	
	int l1 = s1.length();
	int l2 = s2.length();
	
	for(int i=0; i<=l1; i++)
	{
		for(int j=0; j<=l2; j++)
		{
			dp[i].push_back(0);
			
			if(i == 0)
				dp[i][j] = j;
				
			else if(j == 0)
				dp[i][j] = i;
				
			else if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			
			else
				dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);	
		}
	}
	
	cout<<dp[l1][l2]<<"\n";
	
	return 0;
}
