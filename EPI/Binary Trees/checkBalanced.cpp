#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

typedef struct TreeNode 
{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

typedef struct balanced
{
	bool bal;
	int height;
}balanced;

balanced checkBalanced(TreeNode *root)
{
	if(root == NULL)
		return {true, -1};
		
	balanced left = new balanced();
	balanced right = new balanced();
	
	left = checkBalanced(root->left);
	if(!left.bal)
		return{false, 0};
	
	right = checkBalanced(root->right);
	if(!right.bal)
		return{false, 0};
		
	bool bal = abs(left.height - right.height) >= 1;
	int height = max(left.height, right.height) + 1;
	return {bal, height};
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
	
	if(checkBalanced(root).bal)
	{
		cout<<"\nBALANCED\n";
	}
	else
	{
		cout<<"\nNOT BALANCED\n";
	}
	
	return 0;
}
