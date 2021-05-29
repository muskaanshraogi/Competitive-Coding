#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

vector<string> grayCode(int n)
{
	vector<string>arr, temp;
	
	if(n == 1)
	{
		arr.push_back("0");
		arr.push_back("1");
	}
	else
	{
		temp = grayCode(n - 1);
		
		for(int i=0; i<temp.size(); i++)
		{
			arr.push_back("0" + temp[i]);
		}
		for(int i=temp.size()-1; i>=0; i--)
		{
			arr.push_back("1" + temp[i]);
		}
	}
	
	return arr;
}

int main()
{
	int n;
	vector<string>arr;
	
	cin>>n;
	
	arr = grayCode(n);
	
	for(int i=0; i<arr.size(); i++)
	{
		cout<<arr[i]<<"\n";
	}
	
	return 0;
}
