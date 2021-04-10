#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, temp, m = 0;
	vector<int>arr;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		arr.push_back(temp);
	}
	
	for(int i=0; i<n; i++)
	{
		if(i <= m)
			m = max(m, i+arr[i]);
	}
	
	if(m >= n)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	
	return 0;
}
