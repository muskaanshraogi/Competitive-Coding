#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long n;
	vector<long long>set1;
	vector<long long>set2;
	
	cin>>n;
	
	if(n % 4 == 0)
	{
		cout<<"YES\n";
		
		for(long long i=1; i<=n/2; i++)
		{
			if(i % 2)
			{
				set1.push_back(i);
				set1.push_back(n - i + 1);
			}
			else
			{
				set2.push_back(i);
				set2.push_back(n - i + 1);
			}
		}
	}
	else if((n-3) % 4 == 0)
	{
		bool add1 = false;
		
		cout<<"YES\n";
		
		set1.push_back(1);
		set1.push_back(2);
		set2.push_back(3);
		
		if(n >= 4)
			set1.push_back(4);
		
		for(long long i=5; i<=n; i += 2)
		{
			if(add1)
			{
				if(i <= n)
					set1.push_back(i);
				if(i+1 <= n)
					set1.push_back(i+1);
			}
			else
			{
				if(i <= n)
					set2.push_back(i);
				if(i+1 <= n)
					set2.push_back(i+1);
			}
			
			add1 = !add1;
		}
	}
	else
	{
		cout<<"NO\n";
	}
	
	if(set1.size())
	{
		cout<<set1.size()<<"\n";
		for(long long i=0; i<set1.size(); i++)
		{
			cout<<set1[i]<<" ";
		}
		cout<<"\n";
		
		cout<<set2.size()<<"\n";
		for(long long i=0; i<set2.size(); i++)
		{
			cout<<set2[i]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
