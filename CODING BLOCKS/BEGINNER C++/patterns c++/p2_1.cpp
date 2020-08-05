#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int no = n;
	for (int i = 1; i <= n; i++)
	{
		for (int space = 1; space < no; space++) {cout << "\t";}
		no--;
		for (int j = i; j <= 2 * i - 1; j++) {	cout << j<<"\t";}
		for (int k = 2 * i - 1; k > i; k--) {	cout << (k - 1)<<"\t";}
		cout << endl;
	}
} 
