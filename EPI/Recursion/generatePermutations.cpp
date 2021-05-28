#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

const int p = 3;

void permute(vector<vector<int>>&ans, vector<int>arr, int l, int r)
{
	if(l == r)
	{
		ans.push_back(arr);
	}
	else
	{
		for(int i=l; i<=r; i++)
		{
			swap(arr[l], arr[i]);
			permute(ans, arr, l+1, r);
			swap(arr[l], arr[i]);
		}
	}
}

int main()
{
	int n, temp;
	vector<vector<int>>ans;
	vector<int>arr;
	
	cin>>n;
	
	
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		arr.push_back(temp);
	}
	
	permute(ans, arr, 0, n-1);
	
	for(int i=0; i<ans.size(); i++)
	{
		for(int j=0; j<ans[i].size(); j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
