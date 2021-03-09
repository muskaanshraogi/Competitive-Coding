#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long n, count=0;
	
	cin>>n;
	
	for(long long i=5; n/i>=1; i*=5)
	{
		count += n/i;
	}
	
	cout<<count<<"\n";
	
	return 0;
}
