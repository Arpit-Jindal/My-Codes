#include<iostream>
using namespace std;
bool binarysearch(int arr[], int first, int last, int x)
{
	if (first > last)
		return false;
	int mid = (first + last) / 2;
	if (arr[mid] == x)
		return true;
	if (x > mid)
		return binarysearch(arr, mid + 1, last, x);
	else
		return binarysearch(arr, first, mid - 1, x);
}
int main()
{
	const int size = 5;
	int arr[size] = {1, 2, 3, 4, 5};
	int x;
	cin >> x;
	int first = 0;
	int last = size - 1;
	cout << binarysearch(arr, first, last, x);
}