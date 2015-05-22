#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000
class MAXHEAP
{
	private:
		int heap[SIZE];
		int heapsize;
	public:
		MAXHEAP(int a[], int s)
		{
			heapsize = s;
			for(int i=0;i<s;i++)
				heap[i] = a[i];

			this->buildHeap();
		}
		int left(int i)
		{
			return 2*i+1;
		}
		int right(int i)
		{
			return 2*i+2;
		}
		int parent(int i)
		{
			return i/2;
		}
		void heapify(int i)
		{
			int l = left(i);
			int r = right(i);
			int largest;
			if( l < heapsize && heap[l] > heap[i])
				largest = l;
			else
				largest = i;

			if( r < heapsize && heap[r] > heap[largest])
				largest = r;
			if(largest != i)
			{
				int tp = heap[largest];
				heap[largest] = heap[i];
				heap[i] = tp;
				heapify(largest);
			}
		}
		void buildHeap()
		{
			for(int i = heapsize/2; i>=0; i--)
				heapify(i);
		}

		int Max()
		{
			return heap[0];
		}
		int extractMax()
		{
			int m = heap[0];
			heap[0] = heap[heapsize-1];
			heapsize--;
			heapify(0);
			return m;
		}
		void increaseKey(int i, int key)
		{
			if(heap[i] <= key)
			{
				heap[i] = key;
				while( i > 1 && heap[i] > heap[parent(i)])
				{
					int tp = heap[i];
					heap[i] = heap[parent(i)];
					heap[parent(i)] = tp;
					i = parent(i);
				}
			}
		}
		void insert(int key)
		{
			heap[heapsize] = INT_MIN;
			increaseKey(heapsize, key);
			heapsize++;
		}
		void printHeap()
		{
			for(int i=0; i<heapsize/2; i++)
				cout<<heap[i]<<"->"<<heap[left(i)]<<"->"<<heap[right(i)]<<endl;
		}
};

int main()
{
	int a[] = {5, 17, 10, 84, 89, 46, -1, 41, -10, 0};
	int s = sizeof(a)/( sizeof(int ));
	MAXHEAP M(a,s);
	M.increaseKey(0, 1000);
	M.printHeap();
	M.insert(100);
	cout<<"After inserting 100\n";
	M.printHeap();
}