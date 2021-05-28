#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

const int p = 3;

void towerOfHanoi(int n, stack<int>pegs[], int from, int to, int use)
{
	if(n > 0)
	{
		towerOfHanoi(n-1, pegs, from, use, to);
		
		pegs[to].push(pegs[from].top());
		pegs[from].pop();
		
		cout<<"Move peg from "<<from + 1<<" to "<<to + 1<<".\n";
		
		towerOfHanoi(n-1, pegs, use, to, from);
	}
}

int main()
{
	int n;
	
	cin>>n;
	
	stack<int>pegs[p];
	
	for(int i=n; i>=0; i--)
	{
		pegs[0].push(i);
	}
	
	towerOfHanoi(n, pegs, 0, 1, 2);
	
	return 0;
}
