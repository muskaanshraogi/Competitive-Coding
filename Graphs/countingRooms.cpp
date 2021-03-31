#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int X[] = {-1, 1, 0, 0 };
int Y[] = {0, 0, -1, 1 };

void dfs(string r[], int n, int m, int i, int j)
{
	r[i][j] = '#';
	
	for(int k=0; k<4; k++)
	{
		int x = i + X[k];
		int y = j + Y[k];
		
		if(x >= 0 && y >= 0 && x < n && y < m && r[x][y] == '.')
			dfs(r, n, m, x, y);
	}
}

int main()
{
	int n, m, count = 0;
	string r[1001];
	
	cin>>n>>m;
	
	for(int i=0; i<n; i++)
	{
		cin>>r[i];
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(r[i][j] == '.')
			{
				count++;
				dfs(r, n, m, i, j);
			}
		}
	}
	
	cout<<count<<"\n";
	
	return 0;
}
