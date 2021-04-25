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

int main()
{
	int a, b, ans;
	string e;
	Stack *top = NULL;
	
	cin>>e;
	
	for(int i=0; i<e.length(); i++)
	{
		if(e[i] >= '0' && e[i] <= '9')
		{
			top = push(top, e[i] - '0');
		}
		else
		{
			if(!isEmpty(top))
			{
				b = peep(top);
				top = pop(top);
			}
			if(!isEmpty(top))
			{
				a = peep(top);
				top = pop(top);
			}
			
			if(e[i] == '+')
			{
				ans = a + b;
			}
			else if(e[i] == '-')
			{
				ans = a - b;
			}
			else if(e[i] == '*')
			{
				ans = a * b;
			}
			else if(e[i] == '/')
			{
				ans = a / b;
			}
			
			top = push(top, ans);
		}
	}
	
	cout<<peep(top)<<"\n";
	
	return 0;
}
