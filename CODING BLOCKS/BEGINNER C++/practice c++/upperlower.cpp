#include<iostream>
using namespace std;

void upperlower(char a) {
	if (a >= 'A' && a <= 'Z') {cout << "upper";}
	else if (a >= 'a' && a <= 'z') {cout << "lower";}
	else {cout << "invalid";}
}

int main() {
	char a;
	cin >> a;
	upperlower(a);
}