#include<iostream>
using namespace std;
int main() {
	int a = 1025;
	int* p = &a;
	int**q = &p;
	cout << "p = " << p << endl;
	cout << "q = " << q << endl << endl;

	cout << "++p = " << ++p << endl;
	cout << "++q = " << ++q << endl << endl;

	cout << "p = " << p << endl;
	cout << "q = " << q << endl << endl;

	cout << "&a = " << &a << endl;
	cout << "&p = " << &p << endl << endl;

	char* p0;
	p0 = (char*)p;
	cout << "p0 = " << p0 << endl;
	cout << "p0+1 = " << p0 + 1 << endl;
}