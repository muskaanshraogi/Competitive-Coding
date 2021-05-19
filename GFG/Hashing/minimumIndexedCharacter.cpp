// { Driver Code Starts
// C++ implementation to find the character in first 
// string that is present at minimum index in second
// string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        // Your code here
        int ans = INT_MAX;
        unordered_map<char, int>table;
        
        for(int i=0; i<str.length(); i++)
        {
            if(table.find(str[i]) == table.end())
            {
                table[str[i]] = i;
            }
        }
        
        for(int i=0; i<patt.length(); i++)
        {
            if(table.find(patt[i]) != table.end())
            {
                ans = min(ans, table[patt[i]]);
            }
        }
        
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    string patt;
	    cin>>str;
	    cin>>patt;
	    Solution obj;
	    int ans = obj.minIndexChar(str, patt);
	    if(ans == -1)cout<<"No character present";
	    else cout<<str[ans];
	    cout<<endl;
	}return 0;
}
  // } Driver Code Ends
