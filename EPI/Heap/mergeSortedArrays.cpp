#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

typedef pair<int, pair<int, int> > ppi;

int main()
{
	int k, n, temp;
	cin>>k;
	
	vector<int>v[k];
	vector<int>ans;
	priority_queue<ppi, vector<ppi>, greater<ppi>>p;
	
	for(int i=0; i<k; i++)
	{
		cin>>n;
		
		for(int j=0; j<n; j++)
		{
			cin>>temp;
			v[i].push_back(temp);
		}
	}
	
	
	for(int i=0; i<k; i++)
	{
		p.push({v[i][0], {i, 0}});
	}
	
	while(!p.empty())
	{
		ppi cur = p.top();
		p.pop();
		
		ans.push_back(cur.first);
		
		int i = cur.second.first;
		int j = cur.second.second;
		
		if(j+1 < v[i].size())
		{
			p.push({v[i][j+1], {i, j+1}});
		}
	}
	
	for(int i=0; i<ans.size(); i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	
	return 0;
}
