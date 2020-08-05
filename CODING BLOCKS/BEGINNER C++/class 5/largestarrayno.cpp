#include <iostream>
using namespace std;

void printarr(int n) {
	int arr[100];
	int ans = -1000000;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		int curnum = arr[i];
		if (curnum >= ans) {ans = curnum;}
	}
	cout << ans;
}

int main() {
	int n;
	cin >> n;
	printarr(n);
}