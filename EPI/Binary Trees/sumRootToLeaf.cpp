#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

typedef struct TreeNode 
{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

int sumRootToLeaf(TreeNode *root, int partialSum)
{
	if(root == NULL)
		return 0;
	
	partialSum = partialSum * 2 + root->data;	
	
	if(root->left == NULL && root->right == NULL)
	{
		return partialSum;
	}	
	
	return sumRootToLeaf(root->left, partialSum) + sumRootToLeaf(root->right, partialSum);
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
	
	cout<<sumRootToLeaf(root, 0)<<"\n";
	
	return 0;
}
