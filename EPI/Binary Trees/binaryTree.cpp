#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

typedef struct TreeNode 
{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

TreeNode *insert(TreeNode *root, int data, queue<TreeNode *>&q)
{
	TreeNode *temp = new TreeNode();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
		
	if(root == NULL)
	{
		root = temp;
		q.push(root);
	}
	else 
	{
		TreeNode *cur = q.front();
		
		if(cur->left == NULL)
		{
			cur->left = temp;
			q.push(cur->left);
		}
		else if(cur->right == NULL)
		{
			cur->right = temp;
			q.push(cur->right);
			q.pop();
		}
	}
	
	return root;
}

bool search(TreeNode *root, int data)
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

void inorderTraversal(TreeNode *root)
{
	if(root)
	{
		inorderTraversal(root->left);
		cout<<root->data<<" ";
		inorderTraversal(root->right);
	}
}

void preorderTraversal(TreeNode *root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void postorderTraversal(TreeNode *root)
{
	if(root)
	{
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		cout<<root->data<<" ";
	}
}

int main()
{
	int choice, data;
	queue<TreeNode *>q;
	
	TreeNode *root = NULL;
	
	while(1)
	{
		cout<<"\n-----BINARY TREE MENU-----\n";
		cout<<"1) Insert node\n";
		cout<<"2) Search node\n";
		cout<<"3) Inorder traversal\n";
		cout<<"4) Preorder traversal\n";
		cout<<"5) Postorder traversal\n";
		cout<<"6) Exit\n";
		
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"\nEnter the number to be inserted:\n";
				cin>>data;
				root = insert(root, data, q);
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
				cout<<"\nPREORDER TRAVERSAL:\n";
				preorderTraversal(root);
				cout<<"\n";
				break;
				
			case 5:
				cout<<"\nPOSTORDER TRAVERSAL:\n";
				postorderTraversal(root);
				cout<<"\n";
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
