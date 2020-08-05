#include<iostream>
using namespace std;
int partition (int arr[], int s, int e)
{
	int i = s - 1;
	int pivot = arr[e];
	for (int j = s; j < e; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[e]);
	return i + 1;
}
void quicksort(int arr[], int s, int e)
{
	if (s >= e) return;
	int p = partition(arr, s, e);
	quicksort(arr, s, p - 1);
	quicksort(arr, p + 1, e);
}
int main()
{
	int arr[] = {6, 5, 3, 7, 9, 2, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	quicksort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " ";
}