#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

pair<int, int> minMax(vector<int>arr, int low, int high)
{
	int mid;
	pair<int, int>r, r1, r2;
	
	if(high - low <= 1)
	{
		r.first = arr[low] < arr[high] ? arr[low] : arr[high];
		r.second = arr[low] < arr[high] ? arr[high] : arr[low];
	}
	else
	{
		mid = (low + high)/2;
		
		r1 = minMax(arr, low, mid); 
		r2 = minMax(arr, mid+1, high);
		
		r.first = r1.first < r2.first ? r1.first : r2.first;
		r.second = r1.second > r2.second ? r1.second : r2.second;
	}
	
	return r;
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
	
	cout<<minMax(arr, 0, n-1).first<<" "<<minMax(arr, 0, n-1).second<<"\n";
	
	return 0;
}
