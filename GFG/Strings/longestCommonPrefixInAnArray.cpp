// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    string prefix(string s1, string s2)
    {
        string res = "";
        
        for(int i=0; i<min(s1.length(), s2.length()); i++)
        {
            if(s1[i] != s2[i])
                break;
                
            res += s1[i];
        }
        
        return res;
    }
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string p = arr[0];
        
        for(int i=0; i<N; i++)
        {
            p = prefix(p, arr[i]);
        }
        
        if(p.length())
            return p;
        return "-1";
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends
