// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    /*  Function to check if str1 can be formed from
    *   str2 after rotation by 2 places
    */
    bool isRotated(string str1, string str2)
    {
        // Your code here
        
        int match1 = 0, match2 = 0;
        
        if(str1.length() == str2.length())
        {
            match1 = 1;
            match2 = 1;
        }
        
        for(int i=0; i<str1.length() && match1; i++)
        {
            if(str1[i] != str2[(i+2) % str2.length()])
            {
                match1 = 0;
            }
        }
        
        for(int i=0; i<str1.length() && match2; i++)
        {
            if(str1[(i+2) % str1.length()] != str2[i])
            {
                match2 = 0;
            }
        }
        
        if(match1 || match2)
            return true;
        return false;
    }

};

// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
