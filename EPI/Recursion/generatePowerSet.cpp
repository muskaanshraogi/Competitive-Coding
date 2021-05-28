#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

void powerSet(vector<vector<int>>&ans, vector<int>arr)
{
	int bitMask, mask, x = pow(2, arr.size());
	
	for(bitMask=1; bitMask<x; bitMask++)
	{
		vector<int>s;
		
		mask = bitMask;
		
		for(int i=0; i<arr.size(); i++)
		{
			if(mask & 1)
			{
				s.push_back(arr[i]);
			}	
			mask = mask >> 1;
		}
		
		ans.push_back(s);
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
	
	powerSet(ans, arr);
	
	cout<<"{}\n";
	
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
