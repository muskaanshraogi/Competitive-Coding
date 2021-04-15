#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

string nextSequence(string s)
{
	int count;
	string result;
	
	for(int i=0; i<s.size(); i++)
	{
		count = 1;
		while(i < s.size() && s[i] == s[i+1])
		{
			i++;
			count++;
		}
		result += to_string(count) + s[i];
	}
	
	return result;
}

int main()
{
	int n;
	string s = "1";
	
	cin>>n;
	
	for(int i=0; i<n-1; i++)
	{
		s = nextSequence(s);
	} 
	
	cout<<s<<"\n";
	
	return 0;
}
