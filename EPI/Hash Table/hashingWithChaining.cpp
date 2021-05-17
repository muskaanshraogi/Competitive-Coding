#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int hashFunction(int key)
{
	return key % 20;
}

void insertItem(vector<int>table[], int value)
{
	int index = hashFunction(value);
	
	table[index].push_back(value);
}

void deleteItem(vector<int>table[], int value)
{
	int index = hashFunction(value);
	
	for(int i=0; i<table[index].size(); i++)
	{
		if(table[index][i] == value)
		{
			table[index].erase(table[index].begin() + i);
			return;
		}
	}
}

pair<int, int> searchItem(vector<int>table[], int value)
{
	int index = hashFunction(value);
	
	for(int i=0; i<table[index].size(); i++)
	{
		if(table[index][i] == value)
		{
			return {index, i};
		}
	}
	
	return {-1, -1};
}

void display(vector<int>table[])
{
	cout<<"\n-----------------HASH TABLE-------------------\n";
	for(int i=0; i<20; i++)
	{
		for(int j=0; j<table[i].size(); j++)
		{
			cout<<table[i][j]<<" -> ";
		}
		cout<<"X\n";
	}
}

int main()
{
	int choice, value;
	vector<int>table[20];
	pair<int, int>res;
	
	do
	{
		cout<<"\n*****HASH TABLE*****\n";
		cout<<"1)Insert Item\n";
		cout<<"2)Delete Item\n";
		cout<<"3)Search Item\n";
		cout<<"4)Display Table\n";
		cout<<"5)Exit\n";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"\nEnter the value:\n";
				cin>>value;
				insertItem(table, value);
				break;
				
			case 2:
				cout<<"\nEnter the value to be deleted:\n";
				cin>>value;
				deleteItem(table, value);
				break;
				
			case 3:
				cout<<"\nEnter the value to be searched:\n";
				cin>>value;
				res = searchItem(table, value);
				if(res.first != -1 && res.second != -1)
				{
					cout<<"\nFound at position "<<res.first<<"with index "<<res.second<<"\n";
				}
				else
				{
					cout<<"\nElement not found\n";
				}
				break;
				
			case 4:
				display(table);
				break;
				
			case 5:
				exit(0);
		}
		
	}while(1);
	
	return 0;
}
