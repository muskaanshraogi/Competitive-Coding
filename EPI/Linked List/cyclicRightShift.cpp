#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

typedef struct ListNode 
{
	int data;
	struct ListNode *next;
}ListNode;

ListNode *insertBack(ListNode *head, int data)
{
	ListNode *current = head;
	ListNode *newNode = new ListNode;
	
	newNode->data = data;
	newNode->next = NULL;
	
	if(head != NULL)
	{
		while(current->next != NULL)
		{
			current = current->next;
		}
		
		current->next = newNode;
	}
	else
	{
		head = newNode;
	}
	
	return head;
}

void display(ListNode *head)
{
	ListNode *current = head;	
	
	cout<<"\nLIST:\n";
	
	while(current != NULL)
	{
		cout<<current->data<<" -> ";
		current = current->next;
	}
	cout<<"NULL\n";
}

int main()
{
	ListNode *head = NULL, *cur1 = NULL, *cur2 = NULL;
	int n, temp, i, k;
	
	cin>>n>>k;
	
	for(i=0; i<n; i++)
	{
		cin>>temp;
		head = insertBack(head, temp);
	}
	
	cur1 = head;
	cur2 = head;
	
	for(i=0; i<k; i++)
	{
		cur2 = cur2->next;
	}
	
	while(cur2->next)
	{
		cur2 = cur2->next;
		cur1 = cur1->next;
	}
	
	cur2->next = head;
	head = cur1->next;
	cur1->next = NULL;
	
	display(head);
	
	return 0;
}
