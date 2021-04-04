#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, x = 0, y = 0, i;
	ll temp, s, sum = 0;
	vector<ll>arr;
	
	cin>>n>>s;
	
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		arr.push_back(temp);
	}
	
	for(i=0; i<n; i++)
	{
		sum += arr[i];
		y = i;
		
		cout<<i+1<<" "<<sum<<"\n";
		
		while(sum > s && x < y)
		{
			sum -= arr[x];
			x++;
		}
		
		if(sum == s)
			break;
	}
	
	 while(x < y && sum != s)
    {
        sum -= arr[x];
        x++;
    }
    	
	
	if(sum == s)
		cout<<x+1<<" "<<y+1<<"\n";
	else
		cout<<"-1\n";
	
	return 0;
}
