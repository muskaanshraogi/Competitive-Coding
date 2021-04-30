#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

typedef struct TreeNode 
{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

void preorderTraversal(TreeNode *root)
{
	stack<TreeNode *>s;
	TreeNode *cur = root;
	
	s.push(root);
	
	while(!s.empty())
	{
		cur = s.top();
		s.pop();
		cout<<cur->data<<" ";
		
		if(cur->right)
		{
			s.push(cur->right);
		}
		if(cur->left)
		{
			s.push(cur->left);
		}
	}
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
	
	cout<<"\nPREORDER TRAVERSAL:\n";
	preorderTraversal(root);
	cout<<"\n";
	
	return 0;
}
