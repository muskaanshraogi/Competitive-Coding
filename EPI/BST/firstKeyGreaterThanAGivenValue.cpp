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

int main()
{
	int n, data;
	
	Bst *root = NULL, *cur = NULL, *temp;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>data;
		root = insert(root, data);
	}
	
	cin>>data;
	
	temp = root;
	while(temp)
	{
		if(temp->data > data)
		{
			cur = temp;
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}
	
	cout<<cur->data<<"\n";
	
	return 0;
}
