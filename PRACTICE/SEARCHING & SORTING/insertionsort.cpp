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
void insertionsort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int value = arr[i];
		int x = i;
		while (x > 0 && value < arr[x - 1])
		{
			arr[x] = arr[x - 1];
			x--;
		}
		arr[x] = value;
	}
}
void insertionsort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
int main() {
	int n;
	cout << "Enter no. of elements \n";
	cin >> n;
	int arr[100];
	inputarr(arr, n);
	insertionsort(arr, n);
	outputarr(arr, n);
}