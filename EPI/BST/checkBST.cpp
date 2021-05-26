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

void inorderTraversal(TreeNode *root, vector<int>&inorder)
{
	if(root)
	{
		inorderTraversal(root->left, inorder);
		inorder.push_back(root->data);
		inorderTraversal(root->right, inorder);
	}
}

int main()
{
	int n, data, flag = 1;
	vector<int>inorder;
	queue<TreeNode *>q;
	
	TreeNode *root = NULL;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>data;
		root = insert(root, data, q);
	}
	
	inorderTraversal(root, inorder);
	
	for(int i=0; i<inorder.size()-1; i++)
	{
		if(inorder[i] >= inorder[i+1])
		{
			flag = 0;
			break;
		}
	}
	
	if(flag)
	{
		cout<<"\nBST\n";
	}
	else
	{
		cout<<"\nNOT BST\n";
	}
	
	return 0;
}
