#include <iostream>
using namespace std;

void input(int arr[], int n) {
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

int nthelement(int arr[], int n, int x) { //linear function time complexity = n
	for (int i = 0; i < n; i++) {
		if (x == arr[i]) {return i;}

	}
	return -1;
}
int main() {
	int n;
	cin >> n;
	int arr[100];
	input(arr, n);
	int x;
	cin >> x;
	cout << nthelement(arr, n, x);
}