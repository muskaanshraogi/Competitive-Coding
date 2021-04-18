// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDitinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDitinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDitinctChars (string S)
{
    // your code here
    
    int lastIdx[26];
    int i = 0, j, l = 0;
    
    for(int i=0; i<26; i++)
    {
        lastIdx[i] = -1;
    }
    
    for(j=0; j<S.length(); j++)
    {
        i = max(i, lastIdx[S[j] - 'a'] + 1);
        
        l = max(l, j - i + 1);
        
        lastIdx[S[j] - 'a'] = j;
    }
    
    return l;
}
