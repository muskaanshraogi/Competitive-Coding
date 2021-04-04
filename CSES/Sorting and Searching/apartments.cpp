#include<bits/stdc++.h>

using namespace std;

int main()
{
	int na, nb, i, j, count = 0;
	long long dif, temp;
	vector<long long>a;
	vector<long long>b;
	
	cin>>na>>nb>>dif;
	
	for(i=0; i<na; i++)
	{
		cin>>temp;
		a.push_back(temp);
	}
	sort(a.begin(), a.end());
	
	for(i=0; i<nb; i++)
	{
		cin>>temp;
		b.push_back(temp);
	}
	sort(b.begin(), b.end());
	
	i = 0;
	j = 0;
	
	while(i <= na-1 && j <= nb-1)
	{
		if(dif >= abs(b[j] - a[i]))
		{
			count++;
			i++;
			j++;
		}
		else if(b[j] > a[i])
		{
			i++;
		}
		else if(b[j] < a[i])
		{
			j++;
		}
	}
	
	cout<<count<<"\n";
	
	return 0;
}
