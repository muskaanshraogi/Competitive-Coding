#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, idx;
	ll c;
	vector<ll>t;
	
	cin>>n;

	for(int i=0; i<n; i++)
	{
		cin>>c;
		
		idx = upper_bound(t.begin(), t.end(), c) - t.begin();
		
		if(idx == t.size())
		{
			t.push_back(c);
		}
		else
		{
			t[idx] = c;
		}
	}
	
	cout<<t.size()<<"\n";
	
	return 0;
}
