#include<bits/stdc++.h>

using namespace std;

bool compare(const pair<long long, long long>&a, const pair<long long, long long>&b)
{
	return a.second < b.second;
}

int main()
{
	int n, count = 1;
	long long t1, t2, curr;
	vector<pair<long long, long long>>m;
	
	cin>>n;
	
	for(int i=0; i<n; i++) 
	{
		cin>>t1>>t2;
		m.push_back(make_pair(t1, t2));
	}
	sort(m.begin(), m.end(), compare);
	
	curr = m[0].second;
	for(int i=1; i<n; i++)
	{
		if(m[i].first >= curr)
		{
			count++;
			curr = m[i].second;
		}
	}
	
	cout<<count<<"\n";
	
	return 0;
}
