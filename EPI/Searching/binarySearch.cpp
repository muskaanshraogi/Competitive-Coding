#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int binarySearch(vector<int>arr, int left, int right, int key)
{
	while(left <= right)
	{
		int mid = left + (right - left)/2;
		
		if(arr[mid] < key)
			left = mid + 1;
		else if(arr[mid] > key)
			right = mid - 1;
		else
			return mid;
	}
	
	return -1;
}

int main()
{
	int n, temp, key;
	vector<int>arr;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		arr.push_back(temp);
	}
	
	cin>>key;
	
	cout<<binarySearch(arr, 0, n-1, key)<<"\n";
	
	return 0;
}
