#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

typedef struct Stack 
{
	char data;
	struct Stack *next;
}Stack;

bool isEmpty(Stack *top)
{
	if(top != NULL)
		return false;
	return true;
}

Stack *push(Stack *top, char data)
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

char peep(Stack *top)
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
	string p;
	bool formed = true;
	Stack *top = NULL;
	
	cin>>p;
	
	for(int i=0; i<p.length() && formed; i++)
	{
		if(p[i] == '[' || p[i] == '{' || p[i] == '(')
		{
			top = push(top, p[i]);
		}
		else
		{
			if(p[i] == ']')
			{
				if(!isEmpty(top) && peep(top) == '[')
				{
					top = pop(top);
				}
				else
				{
					formed = false;
				}
			}
			else if(p[i] == '}')
			{
				if(!isEmpty(top) && peep(top) == '{')
				{
					top = pop(top);
				}
				else
				{
					formed = false;
				}
			}
			else if(p[i] == ')')
			{
				if(!isEmpty(top) && peep(top) == '(')
				{
					top = pop(top);
				}
				else
				{
					formed = false;
				}
			}
		}
	}
	
	if(formed && isEmpty(top))
		cout<<"WELL-FORMED\n";
	else
		cout<<"NOT WELL-FORMED\n";
	
	return 0;
}
