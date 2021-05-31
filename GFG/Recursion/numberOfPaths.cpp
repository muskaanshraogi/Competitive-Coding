// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
void paths(long long &num, int x, int y, int m, int n)
{
    // Code Here
    
    if(x >= m || y >= n)
        return;
        
    if(x == m - 1 && y == n - 1)
        num++;
        
    paths(num, x+1, y, m, n);
    paths(num, x, y+1, m, n);
}

long long numberOfPaths(int m, int n)
{
    long long num = 0;
    
    paths(num, 0, 0, m, n);
    
    return num;
}

// { Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
