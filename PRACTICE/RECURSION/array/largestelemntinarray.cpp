#include<iostream>
using namespace std;
int largest(int arr[], int start, int end)
{
	if (start == end)
		return arr[start];
	else
		return max(arr[start], largest(arr, start + 1, end));
}
int main()
{
	int arr[5] = {2, 5, 9, 7, 3};
	cout << largest(arr, 0, 4);

}