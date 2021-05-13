#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int binarySearchEqual(vector<int>arr, int left, int right)
{
	while(left <= right)
	{
		int mid = left + ((right - left)/2);
		int dif = arr[mid] - mid;
		
		if(dif < 0)
			left = mid + 1;
		else if(dif > 0)
			right = mid - 1;
		else
			return mid;
	}
	
	return -1;
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
	
	cout<<binarySearchEqual(arr, 0, n-1)<<"\n";
	
	return 0;
}
