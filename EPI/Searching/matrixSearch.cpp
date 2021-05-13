#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

pair<int, int> binarySearch(vector<int>arr[], int key)
{
	int row = 0, col = arr[0].size() - 1;
	
	while(row < arr[0].size() && col >= 0)
	{
		if(arr[row][col] < key)
			row++;
		else if(arr[row][col] > key)
			col--;
		else
			return {row, col};
	}
	
	return {-1, -1};
}

int main()
{
	int n, temp, key;
	
	cin>>n;
	
	vector<int>arr[n];
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>temp;
			arr[i].push_back(temp);
		}
	}
	
	cin>>key;
	
	cout<<binarySearch(arr, key).first<<" "<<binarySearch(arr, key).second<<"\n";
	
	return 0;
}
