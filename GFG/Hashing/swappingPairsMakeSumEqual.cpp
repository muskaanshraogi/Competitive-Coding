// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        int i, j, sum1 = 0, sum2 = 0, target, dif;
        
        sort(A, A+n);
        sort(B, B+m);
        
        for(i=0; i<n; i++)
            sum1 += A[i];
            
        for(i=0; i<m; i++)
            sum2 += B[i];
            
        if((sum1 - sum2) % 2)
            return -1;
        else
            target = (sum1 - sum2)/2;
         
        i = 0;
        j = 0;
        while(i < n && j < m)
        {
            dif = A[i] - B[j];
            
            if(dif == target)
            {
                return 1;
            }
            else if(dif < target)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        
        return -1;
	}
 

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends
