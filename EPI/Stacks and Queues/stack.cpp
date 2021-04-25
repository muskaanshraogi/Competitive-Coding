#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

typedef struct Stack 
{
	int data;
	struct Stack *next;
}Stack;

bool isEmpty(Stack *top)
{
	if(top != NULL)
		return false;
	return true;
}

Stack *push(Stack *top, int data)
{
	Stack *temp = new Stack;
	
	temp->data = data;
	temp->next = top;
	top = temp;
	
	return top;
}

Stack *pop(Stack *top)
{
	Stack *temp;
	
	temp = top;
	top = top->next;
	
	delete(temp);
	
	return top;
}

int peep(Stack *top)
{	
	return top->data;
}

void display(Stack *top)
{	
	Stack *temp = top;
	
	if(!isEmpty(top))
	{
		cout<<"\nSTACK:\n";
		
		while(temp)
		{
			cout<<temp->data<<"\n";
			temp = temp->next;
		}
	}
	else
	{
		cout<<"\nStack is empty\n";
	}
}

int main()
{
	int choice, p, data;
	bool empty;
	Stack *top = NULL;
	
	while(1)
	{
		cout<<"\n-----LINKED LIST MENU-----\n";
		cout<<"1) Push\n";
		cout<<"2) Pop\n";
		cout<<"3) Peep\n";
		cout<<"4) Display stack\n";
		cout<<"5) Check empty\n";
		cout<<"6) Exit\n";
		
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"\nEnter the number to be pushed:\n";
				cin>>data;
				top = push(top, data);
				break;
				
			case 2:
				top = pop(top);
				break;
				
			case 3:
				p = peep(top);
				cout<<"\nThe top element is "<<p<<"\n";
				break;
				
			case 4:
				display(top);
				break;
				
			case 5:
				empty = isEmpty(top);
				if(empty)
					cout<<"\nStack is empty\n";
				else
					cout<<"\nStack is not empty\n";
				break;
				
			case 6:
				exit(0);
			default:
				cout<<"\nEnter a valid option.\n";
				break;
		}
	}
	
	return 0;
}
