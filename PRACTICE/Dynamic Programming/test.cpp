#include<bits/stdc++.h>
using namespace std;
bool isPowerOfFour(int num) {
	int count0 = 0, flag = 0;
	for (int i = 0; i < 32; i++) {
		int mask = (1 << i);
		int x = mask & num;
		if (x && flag)return false;
		if (x)flag = 1;
		else if (!x && !flag)count0++;
	}
	cout << count0 << endl;
	if (count0 & 1)return false;
	return true;
}
int main() {
	cout << isPowerOfFour(16) << endl;
}