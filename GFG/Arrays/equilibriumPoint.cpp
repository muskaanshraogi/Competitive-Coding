// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        int i = 0, j = n - 1, sf = 0, sb = 0;
        
        if(n == 1)
            return 1;
        if(n == 2)
            return -1;
        
        while(i <= j)
        {
            if(sf > sb)
            {
                sb += a[j--];
            }
            else if(sb > sf)
            {
                sf += a[i++];
            }
            else
            {
                if(i == j)
                {
                    return i+1;
                }
                
                sb += a[j--];
                sf += a[i++];
            }
        }
        
        return -1;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
