#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, temp, idx = 1;
	vector<int>arr;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		arr.push_back(temp);
	}
	
	for(int i=1; i<n; i++)
	{
		if(arr[i] != arr[idx-1])
		{
			arr[idx++] = arr[i];
		}
	}
	
	for(int i=0; i<idx; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
	
	return 0;
}
