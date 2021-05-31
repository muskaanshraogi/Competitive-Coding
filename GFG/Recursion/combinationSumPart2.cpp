// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    void combination(vector<vector<int>>&combo, vector<int>&temp, vector<int>A, int l, int sum, int N, int B)
    {
        if(sum == B)
        {
            combo.push_back(temp);
            return;
        }
        
        for(int i=l; i<N; i++)
        {
            if(sum + A[i] <= B)
            {
                temp.push_back(A[i]);
                
                combination(combo, temp, A, i+1, sum+A[i], N, B);
                
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int> &A, int N, int B){
        // code here
        
        sort(A.begin(), A.end());
        
        vector<vector<int>>combo;
        vector<int>temp;
        
        combination(combo, temp, A, 0, 0, N, B);
        
        return combo;
    }
    
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N, x, B;
        cin>>N;
        vector<int> A;
        for(int i = 0;i < N;i++)
        {
            cin>>x;
            A.push_back(x);
        }
        cin>>B;
        
        Solution ob;
        vector<vector<int>> result;
        result = ob.combinationSum(A, N, B);
        
        if(result.size() == 0)
        cout<<"Empty"<<endl;
        else{
            for(int i = 0;i < result.size(); i++){
                cout<<"(";
                for(int j = 0; j < result[i].size();j++){
                    cout<<result[i][j];
                    if(j < result[i].size() - 1)
                    cout<<" ";
                }
                cout<<")";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
