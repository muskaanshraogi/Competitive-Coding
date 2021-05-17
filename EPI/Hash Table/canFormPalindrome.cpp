#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int odd = 0;
	string s;
	unordered_map<char, int>table;
	
	cin>>s;
	
	for(int i=0; i<s.length(); i++)
	{
		table[s[i]]++;
	}
	
	for(auto x : table)
	{
		if(x.second % 2)
			odd++;
	}
	
	if(odd > 1)
		cout<<"NOT PALINDROME\n";
	else
		cout<<"PALINDROME\n";
	
	return 0;
}
