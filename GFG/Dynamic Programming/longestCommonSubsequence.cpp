// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int l[x+1][y+1];
        
        for(int i=0; i<=x; i++)
        {
            for(int j=0; j<=y; j++)
            {
                if(i == 0 || j == 0)
                {
                    l[i][j] = 0;
                }
                else if(s1[i-1] == s2[j-1])
                {
                    l[i][j] = l[i-1][j-1] + 1;
                }
                else
                {
                    l[i][j] = max(l[i-1][j], l[i][j-1]);
                }
            }
        }
        
        return l[x][y];
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends
