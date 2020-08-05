#include <iostream>
using namespace std;

void input(int arr[], int n) {
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

bool twopointer(int arr[], int n, int x) {

	
}

int main() {
	int n;
	cin >> n;
	int arr[100];
	input(arr, n);
	int x;
	cin >> x;
	cout << twopointer(arr, n, x);
}