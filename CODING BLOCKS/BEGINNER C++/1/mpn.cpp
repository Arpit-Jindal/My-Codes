#include <iostream>
using namespace std;
int main() {
	int m, n;
	cout << "enter m\n";
	cin >> m;
	cout << "enter n\n";
	cin >> n;
	int ans = 1;
	for (int i = 1; i <= m; i++) {
		ans = ans * n ;
	}
	cout << ans;
}