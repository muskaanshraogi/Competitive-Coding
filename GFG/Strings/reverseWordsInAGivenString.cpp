// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
  public:
    string reverseWords(string S) 
    { 
        // code here 
        int start = 0, end;
        
        reverse(S.begin(), S.end());
        
        S += '.';
        
        while(end != string::npos)
        {
            end = S.find(".", start);
            reverse(S.begin() + start, S.begin() + end);
            start = end + 1;
        }
        
        S.pop_back();
        
        return S;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends
