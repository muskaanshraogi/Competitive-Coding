// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    
	    int m = 0;
	    
	    for(int i=0; i<n; i++)
	    {
	        m = max(m, arr[i]);
	    }
	    
	    int hash[m+1] = {0};
	    
	    for(int i=0; i<n; i++)
	    {
	        hash[arr[i]]++;
	    }
	    
	    for(int i=0; i<m; i++)
	    {
	        if(hash[i])
	        {
	            for(int j=0; j<m; j++)
	            {
	                if(i != j && hash[j])
	                {
	                    int val = sqrt(i*i + j*j);
	                    
	                    if(val * val == (i*i + j*j) && val < m && hash[val])
	                        return true;
	                }
	            }
	        }
	    }
	    
	    return false;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
  // } Driver Code Ends
