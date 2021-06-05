// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        int result = 0;
        int lcs[n+1][m+1];
        
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                if(i == 0 || j == 0)
                {
                    lcs[i][j] = 0;
                }
                else if(s1[i-1] == s2[j-1])
                {
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                    result = max(result, lcs[i][j]);
                }
                else
                {
                    lcs[i][j] = 0;
                }
            }
        }
        
        return result;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
