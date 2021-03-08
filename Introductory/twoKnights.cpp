#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	__uint128 ans;
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		ans = i*i * (i*i - 1) / 2;
		ans -= 4 * (i - 1) * (i - 2);
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
