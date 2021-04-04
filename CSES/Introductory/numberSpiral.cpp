#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	
	cin>>t;
	
	while(t--)
	{
		long long r, c, max, max2, ans;
		
		cin>>r>>c;
		
		max = r > c ? r : c;
		
		max2 = (max - 1) * (max - 1);
		
		if(max % 2)
		{
			if(r == max)
				ans = max2 + c;
			else
				ans = max2 + 2 * max - r;
		}
		else
		{
			if(c == max)
				ans = max2 + r;
			else
				ans = max2 + 2 * max - c;
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
