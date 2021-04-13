// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        
        int left[n+1], right[n+1], m = INT_MIN, water = 0;
        
        for(int i=0; i<n; i++)
        {
            m = max(m, arr[i]);
            left[i] = m;
        }
        
        m = INT_MIN;
        for(int i=n-1; i>=0; i--)
        {
            m = max(m, arr[i]);
            right[i] = m;
        }
        
        for(int i=0; i<n; i++)
        {
            water += min(left[i], right[i]) - arr[i];
        }
        
        return water;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
