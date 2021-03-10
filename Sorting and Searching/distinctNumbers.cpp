#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, count = 1;
	long long temp;
	vector<long long>arr;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		arr.push_back(temp);
	}
	
	sort(arr.begin(), arr.end());
	
	for(int i=1; i<n; i++)
	{
		if(arr[i] != arr[i-1])
			count++;
	}
	
	cout<<count<<"\n";
	
	return 0;
}
