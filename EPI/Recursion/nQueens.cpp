#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

void print(vector<int>board, int n)
{
	cout<<"\n";
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(board[i] == j)
			{
				cout<<"Q ";
			}
			else
			{
				cout<<"- ";
			}
		}
		cout<<"\n";
	}
}

bool isSafe(vector<int>&board, int row, int col)
{
	for(int i=1; i<=row; i++)
	{
		if(board[i] == col || i + board[i] == row + col || i - board[i] == row - col)
			return false;
	}
	
	return true;
}

void nQueens(vector<int>&board, int row, int n)
{
	if(row >= n+1)
	{
		print(board, n);
		return;
	}
	
	for(int i=1; i<=n; i++)
	{
		if(isSafe(board, row, i))
		{
			board[row] = i; 
			nQueens(board, row+1, n);
			board[row] = 0;
		}
	}
}

int main()
{
	int n;
	vector<int>board;
	
	cin>>n;
	
	for(int i=0; i<=n; i++)
	{	
		board.push_back(0);
	}
	
	nQueens(board, 1, n);
	
	return 0;
}
