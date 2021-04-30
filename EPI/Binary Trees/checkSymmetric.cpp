#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

typedef struct TreeNode 
{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

bool checkSymmetric(TreeNode *root1, TreeNode *root2)
{
	if(root1 == NULL && root2 == NULL)
		return true;
		
	else if(root1 != NULL && root2 != NULL)
	{
		return root1->data == root2->data &&
			   checkSymmetric(root1->left, root2->right) &&
			   checkSymmetric(root1->right, root2->left);
	}	
	
	return false;
}

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



int main()
{
	int n, data;
	queue<TreeNode *>q;
	
	TreeNode *root = NULL;
	
	cin>>n;
		
	for(int i=0; i<n; i++)
	{
		cin>>data;
		root = insert(root, data, q);
	}
	
	if(root == NULL || checkSymmetric(root->left, root->right))
	{
		cout<<"\nSYMMETRIC\n";
	}
	else
	{
		cout<<"\nNOT SYMMETRIC\n";
	}
	
	return 0;
}
