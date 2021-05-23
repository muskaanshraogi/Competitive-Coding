#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, start, end, m = 0, count = 0;
	vector<pair<int, int>>t;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>start>>end;
		t.push_back({start, 1});
		t.push_back({end, -1});
	}
	
	sort(t.begin(), t.end());
	
	for(int i=0; i<t.size(); i++)
	{
		count += t[i].second;
		m = max(m, count);
	}
	
	cout<<m<<"\n";
	
	return 0;
}
