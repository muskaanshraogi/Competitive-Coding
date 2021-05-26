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

void kLargest(Bst *root, vector<int>&arr, int k)
{
	if(root && arr.size() < k)
	{
		kLargest(root->right, arr, k);
		
		if(arr.size() < k)
		{
			arr.push_back(root->data);
		}
		
		kLargest(root->left, arr, k);
	}
}

int main()
{
	int n, data, k;
	vector<int>arr;
	Bst *root = NULL;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>data;
		root = insert(root, data);
	}
	cin>>k;
	
	kLargest(root, arr, k);
	
	for(int i=0; i<arr.size(); i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
	
	return 0;
}
