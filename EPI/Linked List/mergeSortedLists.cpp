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
	ListNode *head1 = NULL, *head2 = NULL, *head = NULL, *cur1, *cur2, *prev;
	int n1, n2, temp, i;
	
	cin>>n1>>n2;
	
	for(i=0; i<n1; i++)
	{
		cin>>temp;
		head1 = insertBack(head1, temp);
	}
	
	for(i=0; i<n2; i++)
	{
		cin>>temp;
		head2 = insertBack(head2, temp);
	}
	
	cur1 = head1;
	cur2 = head2;
	
	if(cur1->data < cur2->data)
	{
		head = head1;
		prev = cur1;
		cur1 = cur1->next;
	}
	else
	{
		head = head2;
		prev = cur2;
		cur2 = cur2->next;
	}
	
	while(cur1 != NULL && cur2 != NULL)
	{
		if(cur1->data < cur2->data)
		{
			prev->next = cur1;
			prev = cur1;
			cur1 = cur1->next;
		}
		else
		{
			prev->next = cur2;
			prev = cur2;
			cur2 = cur2->next;
		}
	}
	
	if(cur1 != NULL)
	{
		prev->next = cur1;
	}
	else if(cur2 != NULL)
	{
		prev->next = cur2;
	}
	
	display(head);
	
	return 0;
}
