#include <iostream>
using namespace std;

int npowerm(int n, int m) {
	if (m == 0) {
		return 1;
	}

	int a2 = npowerm(n, m / 2);

	if (m % 2 == 1) {
		return n * a2 * a2;
	}
	
	return a2 * a2;


}

int main() {
	int n, m;
	cin >> n >> m;
	cout << npowerm(n, m);
}