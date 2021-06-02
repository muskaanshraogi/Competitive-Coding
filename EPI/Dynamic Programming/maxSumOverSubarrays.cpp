#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int maxSumOverSubarrays(vector<int>arr)
{
	int m = INT_MIN;
	vector<int>sum;
	
	sum.push_back(arr[0]);
	
	for(int i=1; i<arr.size(); i++)
	{
		sum.push_back(sum[i-1] + arr[i]);
		
		m = max(m, sum[i]);
		
		if(sum[i] < 0)
			sum[i] = 0;
	}
	
	return m;
}

int main()
{
	int n, temp;
	vector<int>arr;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		arr.push_back(temp);
	}
	
	cout<<maxSumOverSubarrays(arr)<<"\n";
	
	return 0;
}
