#include <iostream>
using namespace std;
int main() {

	int N;
	cout << "enter any number\n";
	cin >> N;
	if (N % 2 == 0)
	{
		cout << "Composite";
		return 0;
	}
	else {
		for (int i = 3; i < sqrt(N); i += 2) {


			if (N % i == 0) cout << "composite";

			return 0;
			else cout << "prime";
		}
	}
}