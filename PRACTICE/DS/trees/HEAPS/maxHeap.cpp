#include<iostream>
#include<climits>
#include<cmath>
using namespace std;
class maxheap
{
	int* A;
	int capacity;
	int heap_size;
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return (2 * i + 2); }
	void Max_Heapify(int i) //downward direction
	{
		int l = left(i);
		int r = right(i);
		int largest = i;
		if (l < heap_size && A[l] > A[largest])
			largest = l;
		if (r < heap_size && A[r] > A[largest])
			largest = r;

		if (largest != i) {
			swap(A[i], A[largest]);
			Max_Heapify(largest);
		}
	}
public:
	maxheap(int size) {
		A = new int[size];
		capacity = size;
		heap_size = 0;
	}
	void insert(int k) //upward direction
	{
		if (heap_size == capacity) {
			cout << "\nOverflow: Could not insertKey\n";
			return;
		}
		heap_size++;
		int i = heap_size - 1;
		A[i] = k;
		while (i > 0 && A[parent(i)] < A[i]) {
			swap(A[parent(i)], A[i]);
			i = parent(i);
		}
	}
	void Delete(int i) {
		increaseKey(i, INT_MAX);
		int a = extractMax();
	}

	void BuildMaxHeap() //used to build heap from an array
	{
		for (int i = heap_size / 2 - 1; i >= 0; i--)
			Max_Heapify(i);
	}
	void printHeap()
	{
		for (int i = 0; i < heap_size; i++)
			cout << A[i] << " ";
		cout << endl;
	}
	int extractMax()
	{
		if (heap_size <= 0)
			return INT_MIN;

		if (heap_size == 1)
			return A[--heap_size];

		int max = A[0];
		A[0] = A[--heap_size];
		Max_Heapify(0);
		return max;
	}
	void increaseKey(int i, int key)
	{
		if (i > heap_size - 1 || i < 0 || key < A[i]) {
			cout << "error\n";
			return;
		}
		A[i] = key;
		while (i > 0 && A[parent(i)] < A[i]) {
			swap(A[parent(i)], A[i]);
			i = parent(i);
		}
	}
	void decreaseKey(int i, int key)
	{
		if (i > heap_size - 1 || i < 0 || key > A[i]) {
			cout << "error\n";
			return;
		}
		A[i] = key;
		Max_Heapify(i);
	}
};
int main()
{
	maxheap H(100);
	H.insert(1); H.insert(2); H.insert(3);
	H.insert(4); H.insert(5); H.insert(6);
	H.printHeap();
	cout << H.extractMax() << endl;
	H.printHeap();
	H.increaseKey(3, 300);
	H.printHeap();
	H.Delete(2);
	H.printHeap();

}