#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n;
	ll temp, miss = 1;
	vector<ll>c;
	vector<bool>dp;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{	
		cin>>temp;
		c.push_back(temp);
	}
	sort(c.begin(), c.end());
	
	for(int i=0; i<n && c[i] <= miss; i++)
		miss += c[i];
		
	cout<<miss<<"\n";
	
	return 0;
}
