#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int curnum;
	int larnum = 0;
	for (int i = 0; i < n; i++)
	{	cin >> curnum;
		if (curnum > larnum) {
			larnum = curnum;

		}


	}
	cout << larnum;
}

