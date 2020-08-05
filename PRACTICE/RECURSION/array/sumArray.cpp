#include<iostream>
using namespace std;
int sum(int arr[], int start, int end)
{
	if (start == end) return arr[end];
	return arr[start] + sum(arr, start + 1, end);
}
int main()
{
	int arr[6] = {2, 6, 15, 4, 31, 8};
	cout << sum(arr, 0, 5);
}