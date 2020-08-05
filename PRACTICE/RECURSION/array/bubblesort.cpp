#include<iostream>
using namespace std;

void bubblesort(int arr[], int size)
{
	if (size == 1) return;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			int temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
	}
	bubblesort(arr, size - 1);
}

int main()
{
	int arr[6] = {9, 12, 3, 44, 35, 6};
	bubblesort(arr, 6);
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << " ";
	}
}