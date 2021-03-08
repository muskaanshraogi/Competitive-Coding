#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	long long max = 0, cur = 1;
	
	cin>>s;
	
	for(long long i=1; i<s.length(); i++)
	{
		if(s[i] == s[i-1])
			cur++;
		else
		{
			max = max > cur ? max : cur;
			cur = 1;
		}
	}
	max = max > cur ? max : cur;
	
	cout<<max<<"\n";
	
	return 0;
}
