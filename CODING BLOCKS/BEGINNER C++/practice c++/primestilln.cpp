#include<iostream>
using namespace std;

bool checkprime(int i) {
	for (int j = 2; j < i; j++) {
		if (i % j == 0) {return false;}
	}
	return true;

}
void printprimes(int n) {
	for (int i = 2; i <= n; i++) {
		if (checkprime(i) == true) {cout << i << endl;}
	}

}
int main() {
	int n;
	cin >> n;
	printprimes(n);
}