#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

typedef struct TreeNode 
{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

void postorderTraversal(TreeNode *root)
{
	stack<TreeNode *>s;
	TreeNode *cur = root;
	
	do
	{
		while(cur != NULL)
		{
			if(cur->right)
			{
				s.push(cur->right);
			}
			s.push(cur);
			cur = cur->left;
		}
		
		cur = s.top();
		s.pop();
		
		if(cur->right && !s.empty() && cur->right == s.top())
		{
			s.pop();
			s.push(cur);
			cur = cur->right;
		}
		else
		{
			cout<<cur->data<<" ";
			cur = NULL;
		}
		
	}while(!s.empty());
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
	
	cout<<"\nPOSTORDER TRAVERSAL:\n";
	postorderTraversal(root);
	cout<<"\n";
	
	return 0;
}
