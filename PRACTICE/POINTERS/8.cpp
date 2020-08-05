#include<iostream>
using namespace std;

int main()
{
	int B[2][3] = {1, 2, 3, 4, 5, 6};
	int* p = *B; //or int (*p)[3]=B;
	cout << B << endl << &B[0] << "\n\n";
	cout << *B << endl << &B[0][0] << endl << B[0] << "\n\n";
	cout << B + 1 << endl << &B[1] << "\n\n";
	cout << *(B + 1) << endl << &B[1][0] << endl << B[1] << "\n\n";
	cout << *(B + 1) + 2 << endl << &B[1][2] << endl << B[1] + 2 << "\n\n";
	cout << *(*B + 1) << endl << B[0][1] << "\n\n";

}