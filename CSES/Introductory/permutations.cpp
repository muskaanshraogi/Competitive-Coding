#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long n, half;
	
	cin>>n;
	
	if(n == 1)
		cout<<"1\n";
	else if(n == 4)
		cout<<"2 4 1 3\n";
	else if(n == 2 || n == 3)
		cout<<"NO SOLUTION\n";
	else
	{
		half = n / 2;
		if(n % 2)
			half++;
			
		for(int i=1; i<=half; i++)
		{
			cout<<i<<" ";
			if(half + i <= n)
				cout<<half+i<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
