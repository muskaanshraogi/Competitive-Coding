#include<bits/stdc++.h>

using namespace std;

int main()
{
	int i, n, temp, no = 1;
	vector<int>arr;
	cin>>n;
	
	for(int i=0; i<n-1; i++)
	{
		cin>>temp;
		arr.push_back(temp);
	}
	
	sort(arr.begin(), arr.end());
	
	for(i=0; i<n-1; i++)
	{
		if(arr[i] == no)
			no++;
		else
		{
			cout<<no<<"\n";
			break;
		}
	}
	
	if(i == n-1)
		cout<<n<<"\n";
	
	return 0;
}
