// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/

int maxLen(int A[], int n)
{
    // Your code here
    int dif = 0, sum = 0;
    unordered_map<int, int>table;
    
    for(int i=0; i<n; i++)
    {
        sum += A[i];
        
        if (A[i] == 0 && dif == 0)
            dif = 1;
        if (sum == 0)
            dif = i + 1;
            
        if(table.find(sum) != table.end())
        {
            dif = max(dif, i - table[sum]);
        }
        else
        {
            table[sum] = i;
        }
    }
    
    return dif;
}

