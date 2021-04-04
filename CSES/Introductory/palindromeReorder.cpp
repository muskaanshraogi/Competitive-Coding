#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long k = 0, pal = 1;
	string s, t;
	
	cin>>s;
	
	t = s;
	
	sort(s.begin(), s.end());
	
	for(long long i=0; i<s.length(); i+=2)
	{
		if(s[i] == s[i+1])
		{
			t[k] = s[i];
			t[s.length()-k-1] = s[i+1];
			k++;
		}
		else
		{
			t[s.length()/2] = s[i];
			i--;
		}
	}
	
	for(long long i=0; i<t.length(); i++)
	{
		if(t[i] != t[t.length()-i-1])
		{
			pal = 0;
			break;
		} 
	}
	
	if(pal)
		cout<<t<<"\n";
	else
		cout<<"NO SOLUTION\n";
}
