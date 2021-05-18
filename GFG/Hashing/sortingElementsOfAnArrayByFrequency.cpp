#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.second == b.second)
        return a.first < b.first;
    
    return (a.second > b.second);
}

int main() {
	//code
	int t;
	
	cin>>t;
	
	while(t--)
	{
	    int n, temp;
	    vector<int>arr;
	    vector<pair<int,int>>arr2;
	    unordered_map<int, int>table;
	    
	    cin>>n;
	    
	    for(int i=0; i<n; i++)
	    {
	        cin>>temp;
	        arr.push_back(temp);
	    }
	    
	    for(int i=0; i<n; i++)
	    {
	        table[arr[i]]++;
	    }
	    
	    for(auto x : table)
	    {
	        arr2.push_back({x.first, x.second});
	    }
	    
	    sort(arr2.begin(), arr2.end(), compare);
	    
	    for(int i=0; i<arr2.size(); i++)
	    {
	        for(int j=0; j<arr2[i].second; j++)
	        {
	            cout<<arr2[i].first<<" ";
	        }
	    }
	    cout<<"\n";
	}
	
	return 0;
}
