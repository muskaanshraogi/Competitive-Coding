// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int, int>table;
        
        if(nums.size() % 2)
            return false;
        
        for(int i=0; i<nums.size(); i++)
        {
            table[((nums[i] % k) + k) % k]++;
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            int rem = ((nums[i] % k) + k) % k;
            
            if(rem * 2 == k)
            {
                if(table[rem] % 2 != 0)
                    return false;
            }
            else if(rem == 0)
            {
                if(table[rem] % 2 != 0)
                    return false;
            }
            else if(table[rem] != table[k - rem])
                return false;
        }
        
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends
