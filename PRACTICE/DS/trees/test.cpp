#include<bits/stdc++.h>
using namespace std;
bool c(int a, int b) {
	return a < b;
}
int main() {
	vector<int> v{1, 2, 7, 6, 5, 4, 3, 2, 1};
	sort(v.begin(), v.end(), c);
	for (auto x : v)cout << x << " ";
}