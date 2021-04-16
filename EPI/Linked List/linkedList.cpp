#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

typedef struct ListNode 
{
	int data;
	struct ListNode *next;
}ListNode;

ListNode *insertFront(ListNode *head)
{
	int data;
	ListNode *newNode = new ListNode;
	
	cout<<"\nEnter the numeric data:\n";
	cin>>data;
	
	newNode->data = data;
	newNode->next = head;
	head = newNode;
	
	return head;
}

ListNode *insertBack(ListNode *head)
{
	int data;
	ListNode *current = head;
	ListNode *newNode = new ListNode;
	
	cout<<"\nEnter the numeric data:\n";
	cin>>data;
	
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

ListNode *insertPos(ListNode *head)
{
	int data, pos, i;
	ListNode *current = head;
	ListNode *newNode = new ListNode;
	
	cout<<"\nEnter position at which data has be inserted:\n";
	cin>>pos;
	cout<<"\nEnter the numeric data:\n";
	cin>>data;
	
	for(i=1; i<pos-1 && current->next != NULL; i++)
	{
		current = current->next;
	}
	
	if(current->next == NULL && i < pos-1)
	{
		cout<<"\nIndex out of range.\n";
	}
	else
	{
		newNode->data = data;
		newNode->next = current->next;
		current->next = newNode;
	}
	
	return head;
}

ListNode *deleteFront(ListNode *head)
{
	ListNode *current = head;
	
	head = current->next;
	
	delete(current);
	
	return head;
}

ListNode *deleteBack(ListNode *head)
{
	ListNode *target, *current = head;
	
	while(current->next->next != NULL)
	{	
		current = current->next;
	}
	
	target = current->next;
	current->next = NULL;
	
	delete(target);
	
	return head;
}

ListNode *deletePos(ListNode *head)
{
	int pos, i;
	ListNode *target, *current = head;
	
	cout<<"\nEnter position from which data has to be deleted:\n";
	cin>>pos;
	
	for(i=1; i<pos-1 && current->next != NULL; i++)
	{
		current = current->next;
	}
	
	if(current->next == NULL && i < pos-1)
	{
		cout<<"\nIndex out of range.\n";
	}
	else
	{
		target = current->next;
		current->next = target->next;
		
		delete(target);
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

int searchData(ListNode *head)
{
	int data, pos = 1;
	
	ListNode *current = head;
	
	cout<<"\nEnter the data to be searched:\n";
	cin>>data;
	
	while(current != NULL)
	{
		if(current->data == data)
		{
			return pos;
		}
		
		pos++;
		current = current->next;
	}
	
	return -1;
}

int main()
{
	int choice, found;
	ListNode *head = NULL;
	
	while(1)
	{
		cout<<"\n-----LINKED LIST MENU-----\n";
		cout<<"1) Insert front\n";
		cout<<"2) Insert back\n";
		cout<<"3) Insert at a position\n";
		cout<<"4) Display list\n";
		cout<<"5) Delete front\n";
		cout<<"6) Delete back\n";
		cout<<"7) Delete at a position\n";
		cout<<"8) Search\n";
		cout<<"9) Exit\n";
		
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				head = insertFront(head);
				break;
				
			case 2:
				head = insertBack(head);
				break;
				
			case 3:
				head = insertPos(head);
				break;
				
			case 4:
				display(head);
				break;
				
			case 5:
				head = deleteFront(head);
				break;
				
			case 6:
				head = deleteBack(head);
				break;
				
			case 7:
				head = deletePos(head);
				break;
				
			case 8:
				found = searchData(head);
				
				if(found != -1)
					cout<<"\nData found at position "<<found<<"\n";
				else
					cout<<"\nData not found.\n";
				break;
				
			case 9:
				exit(0);
			default:
				cout<<"\nEnter a valid option.\n";
				break;
		}
	}
	
	return 0;
}
