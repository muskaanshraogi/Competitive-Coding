#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

vector<int>f;

int fibonacci(int n)
{
	if(n < f.size())
	{
		return f[n];
	}
	else
	{
		f.push_back(fibonacci(n-1) + fibonacci(n-2));
	}
	
	return f[n];
}

int main()
{
	int n;
	
	cin>>n;
	
	f.push_back(0);
	f.push_back(1);
	
	cout<<fibonacci(n-1)<<"\n";
	
	return 0;
}
