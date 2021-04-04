#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n;
	ll temp, median, count = 0;
	vector<ll>c;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{	
		cin>>temp;
		c.push_back(temp);
	}
	
	nth_element(c.begin(), c.begin()+n/2, c.end());
	median = c[n/2];
	
	if(n % 2 == 0)
	{
		nth_element(c.begin(), c.begin()+(n-1)/2, c.end());
		median += c[(n-1)/2];
		median /= 2;
	}
	
	for(int i=0; i<n; i++)
		count += abs(median - c[i]);
		
	cout<<count<<"\n";
	
	return 0;
}
