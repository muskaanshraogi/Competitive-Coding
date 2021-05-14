#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int kthLargest(vector<int>arr, int k)
{
	int i, j;
	int left = 0, right = arr.size() - 1;
	
	while(left < right)
	{
		int pivot = left;
		
		i = left;
		j = right + 1;
		
		do
		{
			do
			{
				i++;
			}while(arr[pivot] > arr[i]);
			
			do
			{
				j--;
			}while(arr[pivot] < arr[j]);
			
			if(i < j)
			{
				swap(arr[i], arr[j]);
			}
		}while(i < j);
		
		swap(arr[j], arr[left]);
		
		if(arr.size() - j == k)
		{
			return arr[j];
		}
		else if(arr.size() - j > k - 1)
		{
			left = j + 1;
		}
		else
		{
			right = j - 1;
		}
	}
}

int main()
{
	int n, temp, k;
	vector<int>arr;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		arr.push_back(temp);
	}
	
	cin>>k;
	
	cout<<kthLargest(arr, k)<<"\n";
	
	return 0;
}
