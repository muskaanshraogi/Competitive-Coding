// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int ans = arr[0];
	    vector<int>sum;
	    
	    sum.push_back(arr[0]);
	    
	    for(int i=1; i<n; i++)
	    {
	        sum.push_back(arr[i]);
	        
	        for(int j=i-1; j>=0; j--)
	        {
	            if(arr[j] < arr[i] && sum[i] < sum[j] + arr[i])
	            {
	                sum[i] = sum[j] + arr[i];
	                ans = max(ans, sum[i]);
	            }
	        }
	    }
	    
	    return ans;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
