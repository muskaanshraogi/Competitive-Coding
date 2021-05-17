#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

string hashFunction(string key)
{
	sort(key.begin(), key.end());
	return key;
}

void insertItem(unordered_map<string, vector<string>>&table, string value)
{
	string index = hashFunction(value);
	
	table[index].push_back(value);
}

void display(unordered_map<string, vector<string>>table)
{
	cout<<"\n";
	for(auto x : table)
	{
		for(int j=0; j<x.second.size(); j++)
		{
			cout<<x.second[j]<<" ";
		}
		cout<<"\n";
	}
}

int main()
{
	int n;
	string s;
	unordered_map<string, vector<string>>table;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>s;
		insertItem(table, s);
	}
	
	display(table);
	
	return 0;
}
