// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
bool compare(struct val &a, struct val &b)
{
    return a.first < b.first;
}

int maxChainLen(struct val p[],int n)
{
//Your code here
    int m = 1;
    vector<int>mcl;
    
    for(int i=0; i<n; i++)
    {
        mcl.push_back(1);
    }
    
    sort(p, p + n, compare);
    
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(p[i].first > p[j].second && mcl[i] < mcl[j] + 1)
            {
                mcl[i] = mcl[j] + 1;
                m = max(m, mcl[i]);
            }
        }
    }
    
    return m;
}
