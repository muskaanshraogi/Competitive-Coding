#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	bool done = false;
	int n, start, end, i = 0;
	pair<int, int>interval, newIt;
	vector<pair<int, int>>s, res;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>start>>end;
		s.push_back({start, end});
	}
	
	cin>>start>>end;
	interval = {start, end};
	
	while(i < n)
	{
		if(s[i].second < interval.first || done)
		{
			res.push_back(s[i]);
		}
		else
		{
			newIt.first = s[i].first < interval.first ? s[i].first : interval.first;
			
			while(s[i].second < interval.second && s[i+1].first <= interval.second)
			{
				i++;
			}
			
			newIt.second = s[i].second > interval.second ? s[i].second : interval.second;
			res.push_back(newIt);
			done = true;
		}
		i++;
	}
	
	for(int i=0; i<res.size(); i++)
	{
		cout<<res[i].first<<" "<<res[i].second<<"\n";
	}
	
	return 0;
}
