// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        int start = 0, len = 0;
        vector<int>res;
        unordered_map<int, int>table;
        
        
        for(int i=0; i<n; i++)
        {
            table[A[i]]++;
            
            if(i - start == k - 1)
            {
                res.push_back(table.size());
                table[A[start]]--;
                
                if(table[A[start]] == 0)
                {
                    table.erase(A[start]);
                }
                
                start++;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
