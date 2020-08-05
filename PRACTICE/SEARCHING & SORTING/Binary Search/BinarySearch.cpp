#include<iostream>
using namespace std;
int BinarySearch(int arr[], int n, int x)
{
	int first = 0;
	int last = n - 1;
	int mid = (first + last) / 2;
	while (first <= last)
	{
		if (arr[mid] == x) return mid;
		else if (arr[mid] > x) last = mid - 1;
		else first = mid + 1;

		mid = (first + last) / 2;
	}
	return -1;
}
int BinarySearchForLoop(int arr[], int n, int x)
{
	for (int first = 0, last = n - 1, mid = (first + last) / 2; first <= last; mid = (first + last) / 2) {
		if (arr[mid] == x) return mid;
		else if (arr[mid] > x) last = mid - 1;
		else first = mid + 1;
	}
	return -1;
}
int recursiveBS(int arr[], int f, int l, int x)
{
	if (f > l)
		return -1;
	int mid = (f + l) / 2;
	if (arr[mid] == x)
		return mid;
	else if (arr[mid] > x)
		return recursiveBS(arr, f, mid - 1, x);
	else
		return recursiveBS(arr, mid + 1, l, x);
}
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 6;
	cout << BinarySearchForLoop(arr, n, x) << endl;
	cout << recursiveBS(arr, 0, n - 1, x);
}