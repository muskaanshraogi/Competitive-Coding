#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int binarySearchSquareRoot(int n)
{
	int left = 0, right = n;
	
	while(left <= right)
	{
		int mid = left + ((right - left)/2);
		
		if(mid*mid <= n)
			left = mid + 1;
		else
			right = mid - 1;
	}
	
	return left - 1;
}

int main()
{
	int n;
	
	cin>>n;
	
	cout<<binarySearchSquareRoot(n)<<"\n";
	
	return 0;
}
