//Find pair of elements which sum to given number
#include<iostream>
#include<unordered_map>
using namespace std;

int getpairscount(int arr[], int n, int sum)
{
	unordered_map<int, int> m;

	for (int i = 0; i < n; i++)
		m[arr[i]]++;

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		int temp = sum - arr[i];
		if (temp != arr[i])
			count += m[temp];
	}
	return count / 2;
}

int main()
{
	int arr[] = {9, 4, 3, 5, 7, 8, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 13;
	cout << getpairscount(arr, n, sum);
}