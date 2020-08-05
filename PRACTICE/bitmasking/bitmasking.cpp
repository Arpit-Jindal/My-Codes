#include<iostream>
#include<cstring>
using namespace std;
int noOfSetbits(int n) {
	int count = 0;
	while (n) {
		count++;
		n = (n & (n - 1));
	}
	return count;
}
pair<int, int> xorSwapping(int a, int b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	return make_pair(a, b);
}
int getithBit(int n, int i) {
	int mask = (1 << i);
	return (n & mask) != 0 ? 1 : 0;
}
int setIthBit(int n, int i) {
	int mask = (1 << i);
	n = (n | mask);
	return n;
}
int clearIthBit(int n, int i) {
	int mask = ~(1 << i);
	n = (n & mask);
	return n;
}
void subsets(char* a) {
	int n = strlen(a);
	for (int i = 1; i < (1 << n); i++) {
		int m = i;//mask
		int ai = 0;//array index
		while (m) {
			if (m & 1) cout << a[ai]; // (m & 1) ? cout << a[ai] :cout <<  "";
			ai++;
			m >>= 1;
		}
		cout << endl;
	}
}
unsigned int reverseBits(unsigned int A) {

	unsigned int ans = 0;
	int i = 31;
	while (A)
	{
		if (A & 1) ans |= 1 << i;
		A >>= 1;
		i--;
	}
	return ans;

	// unsigned int ans = A;
	// int i = 31;
	// A >>= 1;
	// while (A)
	// {
	// 	ans <<= 1;
	// 	ans = (ans | (A & 1));
	// 	A >>= 1;
	// 	i--;
	// }
	// ans <<= i;
	// return ans;
}
int main()
{
	// pair<int, int> p = xorSwapping(5, 7);
	// cout << p.first << " " << p.second << endl;
	// cout << getithBit(5, 0);
	// cout << clearIthBit(13, 0);
	char c[] = "abc";
	subsets(c);
}