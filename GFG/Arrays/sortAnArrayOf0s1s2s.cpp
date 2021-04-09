// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // coode here 
        int left = 0, mid = 0, right = n, pivot = 1;
        
        while(mid < right)
        {
            if(a[mid] < pivot)
            {
                swap(a[left++], a[mid++]);
            }
            else if(a[mid] == pivot)
            {
                mid++;
            }
            else
            {
                swap(a[mid], a[--right]);
            }
        }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends
