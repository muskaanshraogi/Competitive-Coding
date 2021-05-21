// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
            string c = "";
            unordered_set<char>table1, table2, table3;
            
            for(int i=0; i<A.length(); i++)
            {
                table1.insert(A[i]);
            }
            
            for(int i=0; i<B.length(); i++)
            {
                if(table1.find(B[i]) == table1.end())
                {
                    table3.insert(B[i]);
                }
            }
            
            for(int i=0; i<B.length(); i++)
            {
                table2.insert(B[i]);
            }
            
            for(int i=0; i<A.length(); i++)
            {
                if(table2.find(A[i]) == table2.end())
                {
                    table3.insert(A[i]);
                }
            }
            
            for(auto x : table3)
            {
                c += x;
            }
            
            sort(c.begin(), c.end());
            
            if(c == "")
            {
                c = "-1";
            }
            
            return c;
        }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
