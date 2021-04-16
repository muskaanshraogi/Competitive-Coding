// { Driver Code Starts
// Initial template for C++

// Program to convert Roman Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;

// Returns decimal value of roman numaral
int romanToDecimal(string &);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}// } Driver Code Ends


// User fuunction teemplate for C++

// str given roman number string
// Returns decimal value of roman numaral
int romanToDecimal(string &str) {
    // code here
    
    int value;
    
    unordered_map<char, int>r = {
        {'I', 1 }, {'V', 5 }, {'X', 10 }, {'L', 50 }, {'C', 100 }, {'D', 500 }, {'M', 1000 }
    };
    
    value = r[str[str.length()-1]];
    
    for(int i=str.length()-2; i>=0; i--)
    {
        if(r[str[i]] >= r[str[i+1]])
        {
            value += r[str[i]];
        }
        else
        {
            value -= r[str[i]];
        }
    }
    
    return value;
}
