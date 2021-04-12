#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, temp, f, s;
	vector<int>arr;
	
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		arr.push_back(temp);
	}
	
	f = n;
	s = n;
	for(int i=n-2; i>=0 && f==n; i--)
	{
		if(arr[i] < arr[i+1])
		{
			f = i;
			for(int j=n-1; j>i && s==n; j--)
			{
				if(arr[j] > arr[f])
				{
					s = j;
				}
			}
		}
	}
	
	if(f == n)
		cout<<"-1\n";
	else
	{
		swap(arr[f], arr[s]);
		reverse(arr.begin()+f+1, arr.end());
		
		for(int i=0; i<n; i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
