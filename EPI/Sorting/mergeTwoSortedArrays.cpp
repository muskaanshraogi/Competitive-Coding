#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n1, n2, temp, i, j, k;
	vector<int>a, b;
	
	cin>>n1;
	
	for(i=0; i<n1; i++)
	{
		cin>>temp;
		a.push_back(temp);
	}
	
	cin>>n2;
	
	for(i=0; i<n2; i++)
	{
		cin>>temp;
		b.push_back(temp);
	}
	
	for(i=n1; i<n1+n2; i++)
	{
		a.push_back(-1);
	}
	
	i = n1 - 1;
	j = n2 - 1;
	k = n1 + n2 - 1;
	
	while(i >= 0 || j >= 0)
	{
		if(a[i] > b[j])
		{
			a[k--] = a[i--];
		}
		else
		{
			a[k--] = b[j--];
		}
	}
	
	while(j >= 0)
	{
		a[k--] = a[j--];
	}
	
	while(i >= 0)
	{
		a[k--] = a[i--];
	}
	
	for(i=0; i<n1+n2; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	
	return 0;
}
