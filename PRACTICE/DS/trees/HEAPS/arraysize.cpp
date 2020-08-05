#include<iostream>
using namespace std;

void test(int* a)
{
	int size = sizeof(a) / sizeof(int);
	cout << "Inside test: " << size;
}

int main()
{
	int* a;
	for (int i = 0; i < 6; ++i)
		*(a + i) = i + 1;

	int size = sizeof(a) / sizeof(a[0]);
	cout << "Inside Main: " << size << endl;
	test(a);
}