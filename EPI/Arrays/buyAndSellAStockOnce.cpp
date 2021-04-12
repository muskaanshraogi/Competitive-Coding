#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, temp, least, profit = 0;
	vector<int>s;
	
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
	}
	
	cout<<profit<<"\n";
	
	return 0;
}
