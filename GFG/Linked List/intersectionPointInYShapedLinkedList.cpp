// { Driver Code Starts
#include<iostream>
#include<stdio.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node *cur1 = head1, *cur2 = head2, *longer = NULL;
    int n1 = 1, n2 = 1;
    
    while(cur1->next)
    {
        n1++;
        cur1 = cur1->next;
    }
    
    while(cur2->next)
    {
        n2++;
        cur2 = cur2->next;
    }
    
    longer = n1 > n2 ? head1 : head2;
    
    for(int i=0; i<abs(n2-n1); i++)
    {
        longer = longer->next;
    }
    
    cur1 = n1 > n2 ? longer : head1;
    cur2 = n1 > n2 ? head2 : longer;
    
    while(cur1 != cur2)
    {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    
    return cur1->data;
}


