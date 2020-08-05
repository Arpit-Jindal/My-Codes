#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int no = n;
		for (int j = 1; j <= i; j++)
		{
			cout << no;
			no--;
		}
		cout << endl;
	}
}