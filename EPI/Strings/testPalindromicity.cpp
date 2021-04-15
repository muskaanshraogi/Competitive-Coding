#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int i, j;
	string s;
	
	getline(cin, s);
	
	i = 0;
	j = s.length() - 1;
	
	while(i < j)
	{
		while(!isalnum(s[i]))
			i++;
		
		while(!isalnum(s[j]))
			j--;
			
		if(i < j && tolower(s[i]) != tolower(s[j]))
		{
			cout<<"NO\n";
			return 0;
		}
		
		i++;
		j--;
	}
	
	cout<<"YES\n";
	
	return 0;
}
