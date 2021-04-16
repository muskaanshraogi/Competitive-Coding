// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	
	    void permute(string S, vector<string>&ans, int l, int r)
	    {
	        if(l == r)
	        {
	            ans.push_back(S);
	        }
	        else
	        {
	            for(int i=l; i<=r; i++)
	            {
	                swap(S[i], S[l]);
	                permute(S, ans, l+1, r);
	                swap(S[i], S[l]);
	            }
	        }
	    }
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>ans;
		    
		    permute(S, ans, 0, S.length()-1);
		    
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
