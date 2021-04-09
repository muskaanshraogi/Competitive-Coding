#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, temp;
	int i, j;
	vector<int>arr;
	
	cin>>n;
	
	for(i=0; i<n; i++)
	{
		cin>>temp;
		arr.push_back(temp);
	}
	
	i = -1;
	j = n;
	
	do
	{
		do
		{
			i++;
		}while(arr[i] % 2 == 0);
		
		do
		{
			j--;
		}while(arr[j] % 2 == 1);
		
		if(i < j)
			swap(arr[i], arr[j]);
	}while(i < j);
	
	for(i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
	
	return 0;
}
