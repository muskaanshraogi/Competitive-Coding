#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int binarySearchSmallest(vector<int>arr, int left, int right)
{
	while(left < right)
	{
		int mid = left + ((right - left)/2);
		
		if(arr[mid] > arr[right])
			left = mid + 1;
		else if(arr[mid] < arr[right])
			right = mid;
	}
	
	return left;
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
	
	cout<<binarySearchSmallest(arr, 0, n-1)<<"\n";
	
	return 0;
}
