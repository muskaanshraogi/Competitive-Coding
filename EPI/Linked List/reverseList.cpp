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
	ListNode *head = NULL, *cur = NULL, *next = NULL, *prev = NULL;
	int n, temp, i;
	
	cin>>n;
	
	for(i=0; i<n; i++)
	{
		cin>>temp;
		head = insertBack(head, temp);
	}
	
	cur = head;
	
	while(cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	
	head = prev;
	
	display(head);
	
	return 0;
}
