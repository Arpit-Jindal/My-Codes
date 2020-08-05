#include <iostream>
using namespace std;
int main () {

	int N;
	cin >> N;
	int n = N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < n; j++)
		{
			cout << " ";
		}
		n--;
		for (int val = 1; val <= (2 * i - 1); val++)
		{
			cout << val;
		}
		cout << endl;
	}
}