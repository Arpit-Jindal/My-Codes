#include<iostream>
using namespace std;

int main() {
	int t; cin >> t;
	int n, k;
	while (t--) {
		cin >> n >> k;
		int sum = 0;
		int slot = 0;
		while (sum < k) {
			slot++;
			sum += slot;
		}
		sum -= slot;
		int firstb = n - slot - 1;
		int secondb = n - (k - sum);
		for (int j = 0; j < n; j++) {
			if (j == firstb || j == secondb) {
				cout << 'b';
				continue;
			}
			cout << 'a';
		}
		cout << "\n";
	}
}