#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, dist = INT_MAX;
	string str;
	vector<string>s;
	unordered_map<string, int>table;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>str;
		s.push_back(str);
	}
	
	for(int i=0; i<n; i++)
	{
		if(table.find(s[i]) != table.end())
		{
			dist = min(dist, i - table[s[i]]);
		}
		
		table[s[i]] = i;
	}
	
	cout<<dist<<"\n";
	
	return 0;
}
