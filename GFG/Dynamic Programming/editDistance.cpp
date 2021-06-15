// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int min(int a, int b, int c) {
        
        if(a <= b && a <= c)
            return a;
        
        if(b <= a && b <= c)
            return b;
            
        return c;
    }
    
    int editDistance(string s, string t) {
        // Code here
        int m = s.length(), n = t.length();
        int dp[m+1][n+1];
        
        for(int i=0; i<=m; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i == 0)
                {
                    dp[i][j] = j;
                }
                else if(j == 0)
                {
                    dp[i][j] = i;
                }
                else if(s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else 
                {
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1;
                }
            }
        }
        
        return dp[m][n];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
