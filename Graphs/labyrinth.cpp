#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int X[] = {-1, 1, 0, 0 };
int Y[] = {0, 0, -1, 1 };

int main()
{
	int n, m, sx, sy, ex, ey, flag = 0;
	string l[1001];
	bool visited[1001][1001];
	int dist[1001][1001];
	queue<pair<int, int>>q;
	vector<pair<int, int>>parent[1001];
	
	cin>>n>>m;
	
	for(int i=0; i<n; i++)
	{
		cin>>l[i];
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			dist[i][j] = 10000;
			parent[i].push_back({ 10000, 10000 });
			if(l[i][j] == 'A')
			{
				sx = i;
				sy = j;
				dist[i][j] = 0;
			}
			else if(l[i][j] == 'B')
			{
				ex = i;
				ey = j;
			}
			
			if(l[i][j] == '#')
			{
				visited[i][j] = true;
			}
			else
			{
				visited[i][j] = false;
			}
		}
	}
	
	q.push({ sx, sy });
	visited[sx][sy] = true;
	
	while(!q.empty())
	{
		pair<int, int>top = q.front();
		q.pop();
		
		if(top.first == ex && top.second == ey)
		{
			flag = 1;
			break;
		}
		
		for(int i=0; i<4; i++)
		{
			int x = top.first + X[i];
			int y = top.second + Y[i];
			
			if(x >= 0 && y >= 0 && x < n && y < m && !visited[x][y] && (l[x][y] == 'B' || l[x][y] == '.'))
			{
				if(dist[x][y] > dist[top.first][top.second])
				{
					dist[x][y] = dist[top.first][top.second] + 1;
					parent[x][y] = { top.first, top.second };
					visited[x][y] = true;
					q.push({ x, y });
				}
			}
		}
	}
	
	if(!flag)
	{
		cout<<"NO\n";
	}
	else
	{
		vector<pair<ll, ll>>ans;
		
		while(ex != 10000 && ey != 10000)
		{
			ans.push_back({ ex, ey });
			int z = parent[ex][ey].first;
			int y = parent[ex][ey].second;
			ex = z;
			ey = y;
		}
		
		reverse(ans.begin(), ans.end());
		
		string a = "";
		
		for(int i=0; i<ans.size()-1; i++)
		{
			int x1 = ans[i].first;
			int y1 = ans[i].second;
			int x2 = ans[i+1].first;
			int y2 = ans[i+1].second;
			
			if(x1 == x2)
			{
				if(y1 > y2)
					a += 'L';
				else
					a +='R';
			}
			else if(y1 == y2)
			{
				if(x1 > x2)
					a += 'U';
				else
					a += 'D';
			}
		}
		
		cout<<"YES\n";
		cout<<a.size()<<"\n";
		for(int i=0; i<a.size(); i++)
			cout<<a[i];
		cout<<"\n";
	}
	
	
	
	return 0;
}
