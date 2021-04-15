#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	string s;
	int value;
	
	unordered_map<char, int>r = {
		{'I', 1 }, {'V', 5 }, {'X', 10 }, {'L', 50 }, {'C', 100 }, {'D', 500 }, {'M', 1000 },
	};
	
	cin>>s;
	
	value = r[s[s.length()-1]];
	
	for(int i=s.length()-2; i>=0; i--)
	{
		if(r[s[i]] >= r[s[i+1]])
		{
			value += r[s[i]];
		}
		else
		{
			value -= r[s[i]];
		}	
	}
	
	cout<<value<<"\n";
	
	return 0;
}
