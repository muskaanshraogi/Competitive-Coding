// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int n)
    {
        // code here
        int i = 9;
        vector<int>p;
        int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        
        while(n)
        {
            while(n < coins[i])
            {
                i--;
            }
            
            if(n - coins[i] >= 0)
            {
                n -= coins[i];
                p.push_back(coins[i]);
            }
            else
            {
                i--;
            }
        }
        
        return p;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends
