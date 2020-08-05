#include<bits/stdc++.h>
using namespace std;
int function(int a) {
	int n = a + 1;
	int ans = n / 2;
	int block_size = 2;
	while (block_size <= n) {
		int blocks = n / block_size;
		ans += (blocks / 2) * block_size;
		if (blocks & 1) {
			ans += (n % block_size);
		}
		block_size *= 2;
	}
	return ans;
}
int main() {

}