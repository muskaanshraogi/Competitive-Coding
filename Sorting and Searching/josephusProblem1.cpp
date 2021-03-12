#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, pos = 0;
	vector<int>j;
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
		j.push_back(i);
		
	while(j.size() > 1)
	{
		pos = (pos+1) % j.size();
		cout<<j[pos]<<" ";
		j.erase(j.begin()+pos);
		pos = pos % j.size();
	}
	
	cout<<j[0]<<"\n";
	
	
	return 0;
}
