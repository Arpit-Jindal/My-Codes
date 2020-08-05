#include <iostream>
using namespace std;

void input(int arr[], int n) {
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

bool existence(int arr[], int n, int x) {

	for (int i = 0; i < n - 1; i++) {
		int first = i;

		for (int j = i + 1; j < n; j++) {
			int second = j;
			if (arr[first] + arr[second] == x ) {return true;}
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	int arr[100];
	input(arr, n);
	int x;
	cin >> x;
	cout << existence(arr, n, x);
}