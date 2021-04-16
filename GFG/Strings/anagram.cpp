// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdbool.h>


 // } Driver Code Ends
//User function Template for C

/*  Function to check if two strings are anagram
*   a, b: input string
*/
bool isAnagram(char a[], char b[]){
    
    // Your code here
    
    int f1[26] = {0};
    int f2[26] = {0};
    
    for(int i=0; i<strlen(a); i++)
    {
        f1[a[i] - 'a']++;
    }
    
    for(int i=0; i<strlen(b); i++)
    {
        f2[b[i] - 'a']++;
    }
    
    for(int i=0; i<26; i++)
    {
        if(f1[i] != f2[i])
            return false;
    }
    
    return true;
}


// { Driver Code Starts.

int main() {
    
    int t;

    scanf("%d", &t);

    while(t--){
        char c[10000], d[10000];

        scanf("%s%s", &c, &d);

        if(isAnagram(c, d)) printf("YES\n");
        else  printf("NO\n");
    }

}
  // } Driver Code Ends
