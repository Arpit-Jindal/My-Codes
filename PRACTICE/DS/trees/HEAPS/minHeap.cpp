#include<iostream>
#include<cmath>
using namespace std;
class minHeap
{
	int* A;
	int capacity;
	int heap_size;
public:
	minHeap(int size)
	{
		A = new int[size];
		capacity = size;
		heap_size = 0;
	}
	int parent(int i) {return (i - 1) / 2;}
	int left(int i) {return 2 * i + 1;}
	int right(int i) {return 2 * i + 2;}
	void insert(int k);
	void Delete(int i);
	void increaseKey(int i, int k);
	void decreaseKey(int i, int k);
	void heapify(int i);
	void printheap();
	int extractMin();
	void printMin();
};
void minHeap::heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && A[l] < A[smallest])
		smallest = l;
	if (r < heap_size && A[r] < A[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(A[smallest], A[i]);
		heapify(smallest);
	}
}
void minHeap::insert(int k)
{
	if (heap_size == capacity)
	{
		cout << "\nOVERFLOW\n";
		return;
	}
	heap_size++;
	int i = heap_size - 1;
	A[i] = k;
	while (i != 0 && A[parent(i)] > A[i]) //heapify in upward direction
	{
		swap(A[parent(i)], A[i]);
		i = parent(i);
	}
}
void minHeap::Delete(int i)
{
	decreaseKey(i, INT_MIN);
	int a = extractMin();
}
void minHeap::increaseKey(int i, int k)
{
	A[i] = k;
	heapify(i);
}
void minHeap::decreaseKey(int i, int k)
{
	A[i] = k;
	while (i != 0 && A[parent(i)] > A[i])
	{
		swap(A[parent(i)], A[i]);
		i = parent(i);
	}
}
void minHeap::printheap()
{
	for (int i = 0; i < heap_size; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
int minHeap::extractMin()
{
	if (heap_size <= 0 )
		return INT_MAX;
	if (heap_size == 1)
		return A[--heap_size];

	int min = A[0];
	A[0] = A[heap_size - 1];
	heap_size--;
	heapify(0);
	return min;
}
void minHeap::printMin()
{
	cout << A[0] << " ";
}
int main()
{
	minHeap heap(100);
	heap.insert(11); heap.insert(3); heap.insert(2);
	heap.insert(1); heap.insert(15); heap.insert(5);
	heap.insert(4); heap.insert(45);
	heap.printheap();
	cout << heap.extractMin() << " ";
	heap.printMin();
}