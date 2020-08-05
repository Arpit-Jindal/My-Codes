#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int cnt = 0;

	while (n>0) {
		int unitdigit = n % 10;
		cnt++;

		n = n / 10;
		
	}
	cout << cnt;
}