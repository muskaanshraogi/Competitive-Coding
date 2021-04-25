// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(struct Node *head)
    {
        struct Node *prev = NULL, *cur = head, *next;
        
        while(cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        head = prev;
        
        return head;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        int offset = 0, sum, data1, data2;
        struct Node *head = NULL, *prev = NULL;
        
        first = reverse(first);
        second = reverse(second);
        
        while(first || second)
        {
            Node *temp = new Node(0);
            
            data1 = first ? first->data : 0;
            data2 = second ? second->data : 0;
            
            sum = data1 + data2 + offset;
            temp->data = sum % 10;
            offset = sum/10;
            
            if(head == NULL)
            {
                head = temp;
                prev = head;
            }
            else
            {
                prev->next = temp;
                prev = temp;
            }
            
            if(first)
                first = first->next;
                
            if(second)
                second = second->next;
        }
        
        if(offset)
        {
            Node *temp = new Node(offset);
            
            prev->next = temp;
            temp->next = NULL;
        }
        
        head = reverse(head);
        
        return head;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends
