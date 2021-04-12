#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n;
	vector<int>p;
	cin>>n;
	
	deque<bool>is_prime(n+1, true);
	is_prime[0] = false;
	is_prime[1] = false;
	
	for(int i=2; i<=n; i++)
	{
		if(is_prime[i])
		{
			p.push_back(i);
			
			for(int j=i; j<=n; j+=i)
			{
				is_prime[j] = false;
			}
		}
	}
	
	for(int i=0; i<p.size(); i++)
	{
		cout<<p[i]<<" ";
	}
	cout<<"\n";
	
	return 0;
}
