#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n1, n2, temp, i, j;
	vector<int>a, b;
	unordered_set<int>ans;
	
	cin>>n1>>n2;
	
	for(i=0; i<n1; i++)
	{
		cin>>temp;
		a.push_back(temp);
	}
	
	for(i=0; i<n2; i++)
	{
		cin>>temp;
		b.push_back(temp);
	}
	
	i = 0;
	j = 0;
	
	while(i < n1 && j < n2)
	{
		if(a[i] < b[j])
		{
			i++;
		}
		else if(a[i] > b[j])
		{
			j++;
		}
		else
		{
			ans.insert(a[i]);
			i++;
			j++;
		}
	}
	
	for(auto x : ans)
	{
		cout<<x<<" ";
	}
	cout<<"\n";
	
	return 0;
}
