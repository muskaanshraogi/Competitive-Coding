#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

typedef struct TreeNode 
{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

bool sumRootToLeaf(TreeNode *root, int partialSum, int target)
{
	if(root == NULL)
		return false;
	
	partialSum += root->data;	
	
	if(root->left == NULL && root->right == NULL)
	{
		return partialSum == target;
	}	
	
	return sumRootToLeaf(root->left, partialSum, target) || sumRootToLeaf(root->right, partialSum, target);
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
	int n, data, t;
	queue<TreeNode *>q;
	
	TreeNode *root = NULL;
	
	cin>>n>>t;
		
	for(int i=0; i<n; i++)
	{
		cin>>data;
		root = insert(root, data, q);
	}
	
	if(sumRootToLeaf(root, 0, t))
	{
		cout<<"\nEXISTS\n";
	}
	else
	{
		cout<<"\nDOES NOT EXIST\n";
	}
	
	return 0;
}
