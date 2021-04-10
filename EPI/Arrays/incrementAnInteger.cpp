#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, temp, sum, carry = 0;
	vector<int>num;
	
	cin>>n;
	while(n--)
	{
		cin>>temp;
		num.push_back(temp);
	}
	
	for(int i=num.size()-1; i>=0; i--)
	{	
		if(i == num.size()-1)
			sum = num[i] + 1;
		else
			sum = num[i] + carry;
			
		if(sum == 10)
		{
			sum = 0;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		
		num[i] = sum;
	}
	
	if(carry)
	{
		num.insert(num.begin(), 1);
	}
	
	for(int i=0; i<num.size(); i++)
	{
		cout<<num[i]<<" ";
	}
	cout<<"\n";
	
	return 0;
}
