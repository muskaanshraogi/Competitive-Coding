	#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int heapSize = 0;

int parent(int i)
{
	return (i - 1)/2;
}

int left(int i)
{
	return 2*i + 1;
}

int right(int i)
{
	return 2*i + 2;
}

int getMin(int *heap)
{
	return heap[0];
}

void maxHeapify(int *heap, int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heapSize && heap[l] > heap[i])
        smallest = l;
    if (r < heapSize && heap[r] > heap[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(heap[i], heap[smallest]);
        maxHeapify(heap, smallest);
    }
}

void insertKey(int *heap, int key)
{
	heapSize++;
	
	int i = heapSize - 1;
	
	heap[i] = key;
	
	while(i != 0 && heap[parent(i)] < heap[i])
	{
		swap(heap[i], heap[parent(i)]);
		i = parent(i);
	}
}

void increaseKey(int *heap, int i, int val)
{
	heap[i] = val;
	
	while(i != 0 && heap[parent(i)] < heap[i])
	{
		swap(heap[i], heap[parent(i)]);
		i = parent(i);
	}
}

int extractMax(int *heap)
{
	if(heapSize <= 0)
		return INT_MIN;
	if(heapSize == 1)
	{
		heapSize--;
		return heap[0];
	}
	
	int root = heap[0];
	heap[0] = heap[heapSize - 1];
	heapSize--;
	maxHeapify(heap, 0);
	
	return root;
}

void deleteKey(int *heap, int i)
{
	increaseKey(heap, i, INT_MAX);
	extractMax(heap);
}

void display(int *heap)
{
	int j = 1, k = 1;
	
	cout<<"\nMAX-HEAP\n";
	cout<<"-----------------------\n";
	for(int i=0, j=1; i<heapSize; i++, j++)
	{
		cout<<heap[i]<<" ";
		
		if(j == k)
		{
			cout<<"\n";
			j = 0;
			k *= 2;
		}
	}
	cout<<"\n";
}

int main()
{
	int *heap;
	int choice, key, i;
	
	do
	{
		cout<<"\n*****MAX-HEAP*****\n";
		cout<<"1)Insert Key\n";
		cout<<"2)Delete Key\n";
		cout<<"3)Decrease Key\n";
		cout<<"4)Display Heap\n";
		cout<<"5)Exit\n";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"\nEnter the key to be inserted:\n";
				cin>>key;
				insertKey(heap, key);
				break;
				
			case 2:
				cout<<"\nEnter index of the key to be deleted:\n";
				cin>>i;
				deleteKey(heap, i);
				break;
			
			case 3:
				cout<<"\nEnter the index to be replaced:\n";
				cin>>i;
				cout<<"\nEnter new key:\n";
				cin>>key;
				increaseKey(heap, i, key);
				break;
				
			case 4:
				display(heap);
				break;
				
			case 5:
				exit(0);
		}
	}while(1);
	
	return 0;
}
