#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	ll x, temp, dist1, dist2;
	int n;
	set<ll>lights;
	multiset<ll>dist;
	
	cin>>x>>n;
	
	lights.insert(0);
	lights.insert(x);
	dist.insert(x);
	
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		
		auto it2 = lights.upper_bound(temp);
		auto it1 = it2;
		it1--;
		
		dist.erase(dist.find(*it2 - *it1));
		
		dist.insert(temp - *it1);
		dist.insert(*it2 - temp);
		
		lights.insert(temp);
		
		auto ans = dist.end();
		ans--;
		cout<<*ans<<" ";
	}
	cout<<"\n";
	
	return 0;
}
