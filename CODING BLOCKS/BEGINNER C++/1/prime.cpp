#include <iostream>
using namespace std;
int main() {

	int n;
	cout << "enter any no.";
	cin >> n;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0) {

			cout << "composite";
			return 0;
		}

	}
	cout << "prime";
}


