#include<bits/stdc++.h>
using namespace std;

int main() {
	int n = 3;
	if (n & 1) {
		cout << "odd " << (n & 1);
	} else {
		cout << "even " << (n & 1);
	}
}