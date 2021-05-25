#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

typedef struct Bst 
{
	int data;
	struct Bst *left, *right;
}Bst;

Bst *insert(Bst *root, int data)
{		
	if(root == NULL)
	{
		Bst *temp = new Bst();
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		
		return temp;
	}
	else if(data < root->data)
	{
		root->left = insert(root->left, data);
	}
	else if(data > root->data)
	{
		root->right = insert(root->right, data);
	}
	
	return root;
}

bool search(Bst *root, int data)
{
	if(root)
	{
		if(root->data == data)
			return true;
		
		if(search(root->left, data) || search(root->right, data))
			return true;
		return false;
	}
	
	return false;
}

void inorderTraversal(Bst *root)
{
	if(root)
	{
		inorderTraversal(root->left);
		cout<<root->data<<" ";
		inorderTraversal(root->right);
	}
}

int main()
{
	int choice, data;
	
	Bst *root = NULL;
	
	while(1)
	{
		cout<<"\n-----BINARY SEARCH TREE MENU-----\n";
		cout<<"1) Insert node\n";
		cout<<"2) Search node\n";
		cout<<"3) Inorder traversal\n";
		cout<<"4) Exit\n";
		
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"\nEnter the number to be inserted:\n";
				cin>>data;
				root = insert(root, data);
				break;
				
			case 2:
				cout<<"\nEnter the number to be searched:\n";
				cin>>data;
				if(search(root, data))
					cout<<"Node found\n";
				else
					cout<<"Node not found\n";
				break;
				
			case 3:
				cout<<"\nINORDER TRAVERSAL:\n";
				inorderTraversal(root);
				cout<<"\n";
				break;
				
			case 4:
				exit(0);
				
			default:
				cout<<"\nEnter a valid option.\n";
				break;
		}
	}
	
	return 0;
}
