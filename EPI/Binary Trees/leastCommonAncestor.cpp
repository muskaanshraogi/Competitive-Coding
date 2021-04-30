#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

typedef struct TreeNode 
{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

typedef struct lca
{
	int num;
	TreeNode *ancestor;
}lca;

lca leastCommonAncestor(TreeNode *root, TreeNode *node1, TreeNode *node2)
{
	if(root == NULL)
		return {0, NULL};
		
	lca left = new lca();
	lca right = new lca();
	
	left = leastCommonAncestor(root->left, node1, node2);
	if(left.num == 2)
		return left;
	
	right = leastCommonAncestor(root->right, node1, node2);
	if(right.num == 2)
		return left;
		
	int num = left.num + right.num + (root == node1) + (root == node2);
	TreeNode *ancestor = num == 2 ? tree : NULL;
	
	return {num, ancestor};
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
	
	cout<<leastCommonAncestor(root, node1, node2).ancestor->data<<"\n";
	
	return 0;
}
