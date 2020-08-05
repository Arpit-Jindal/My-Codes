#include <iostream>
using namespace std;

void inputarr(int arr[], int n)
{
	cout << "Enter " << n << " elements: \n";
	for (int i = 0; i < n; i++) cin >> arr[i];
}
void outputarr(int arr[], int n)
{
	cout << "The sorted array: \n";
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

void selectionsort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int imin = i;
		for (int j = i + 1; j < n ; j++)
		{
			if (arr[imin] > arr[j])
				imin = j;
		}
		if (imin != i) {
			swap(arr[imin], arr[i]);
		}
	}
}

void recursive_selection_sort(int arr[], int n, int i)
{
	if (i >= n - 1) return;

	int imin = i;
	for (int j = i + 1; j < n; j++)
	{
		if (arr[j] < arr[imin]) imin = j;
	}
	if (imin != i) swap(arr[imin], arr[i]);

	recursive_selection_sort(arr, n, i + 1);
}



int main() {
	int n;
	cout << "Enter no. of elements \n";
	cin >> n;
	int arr[100];
	inputarr(arr, n);
	// recursive_selection_sort(arr, n, 0);
	selectionsort(arr, n);
	outputarr(arr, n);
}