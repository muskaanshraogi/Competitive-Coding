#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int r, c;
	vector<vector<int>>dp;
	
	cin>>r>>c;
	
	for(int i=0; i<r; i++)
	{
		vector<int>temp;
		
		for(int j=0; j<c; j++)
		{
			if(i == 0 && j == 0)
			{
				temp.push_back(1);
			}
			else
			{
				temp.push_back(0);
				
				if(i > 0)
				{
					temp[j] += dp[i-1][j];
				}
				if(j > 0)
				{
					temp[j] += temp[j-1];
				}
			}
		}
		
		dp.push_back(temp);
	}

	cout<<dp[r-1][c-1]<<"\n";
	
	return 0;
}
