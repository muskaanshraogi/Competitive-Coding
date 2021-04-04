#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, temp, count = 1;
	vector<int>arr, idx;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		arr.push_back(temp);
		idx.push_back(0);
	}
	
	for(int i=0; i<n; i++)
	{
		idx[arr[i]] = i+1;
	}
	
	for(int i=2; i<=n; i++)
	{
		if(idx[i] < idx[i-1])
		{
			count++;
		}
	}
	
	cout<<count<<"\n";
	
	return 0;
}
