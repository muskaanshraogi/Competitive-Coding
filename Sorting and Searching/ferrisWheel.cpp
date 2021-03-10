#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, i, j, count = 0;
	long long max, temp;
	vector<long long>c;
	
	cin>>n>>max;
	
	for(i=0; i<n; i++)
	{
		cin>>temp;
		c.push_back(temp);
	}
	sort(c.begin(), c.end());
	
	i = 0;
	j = n - 1;
	
	while(i <= j)
	{
		while(c[j] >= max)
		{
			j--;
			count++;
		}
		
		if(c[j] < max)
		{
			if(c[j] + c[i] <= max)
			{
				i++;
			}
			
			j--;
			count++;
		}
	}
	
	cout<<count++<<"\n";
	
	return 0;
}
