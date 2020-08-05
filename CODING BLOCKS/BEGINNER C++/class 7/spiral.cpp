#include <iostream>
using namespace std;

void input(int arr[][100], int n , int m) {
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}
void output	(int arr[][100], int n , int m) {

	int firstrow = 0;
	int lastcol = m - 1;
	int lastrow = n - 1;
	int firstcol = 0;
	while (firstrow <= lastrow && firstcol <= lastcol) {
		for (int j = firstcol; j <= lastcol; j++) {
			cout << arr[firstrow][j] << ", ";
		}
		firstrow++;
		for (int i = firstrow; i <= lastrow; i++) {
			cout << arr[i][lastcol] << ", ";
		}
		lastcol--;
		for (int j = lastcol; firstrow <= lastrow && j >= firstcol; j--) {
			cout << arr[lastrow][j] << ", ";
		}
		lastrow--;
		for (int i = lastrow; firstcol <= lastcol && i >= firstrow; i--) {
			cout << arr[i][firstcol] << ", ";
		}
		firstcol++;

	}
	cout<<"END";

}
int main() {
	int n, m;
	cin >> n >> m;
	int arr[100][100];
	input(arr, n, m);
	output(arr, n, m);
}