#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	long long temp, moves = 0;
	vector<long long>arr;
	
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		arr.push_back(temp);
	}
	
	for(int i=1; i<n; i++)
	{
		if(arr[i-1] > arr[i])
		{
			moves += arr[i-1] - arr[i];
			arr[i] = arr[i-1];
		}
	}
	
	cout<<moves<<"\n";
	
	return 0;
}
