// { Driver Code Starts
 #include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
        /*You are required to complete this method */
    int atoi(string str)
    {
        //Your code here
        int mul = 1, val = 0;
        
        for(int i=str.length()-1; i>=0; i--)
        {
            if(str[i] - '0' >= 0 && str[i] - '0' <= 9)
            {
                val += (str[i] - '0') * mul;
                mul *= 10;
            }
            else if(i == 0 && str[i] == '-')
            {
                val = -val;
            }
            else
            {
                return -1;
            }
        }
        
        return val;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends
