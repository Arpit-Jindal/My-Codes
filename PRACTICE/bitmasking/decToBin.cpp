#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 31; i >= 0; i--)
	{
		int k = n >> i;
		cout << (k & 1);
	}
	cout << endl;
}