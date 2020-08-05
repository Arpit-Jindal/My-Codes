#include<bits/stdc++.h>
using namespace std;
string multiple(int A) {
	if (A == 1) return "1";
	vector<int> last_rem(A, -1), choice(A, -1);
	queue<int> q;
	q.push(1);
	while (1) {
		int r = q.front(); q.pop();
		if (r == 0) break;
		int x = (r * 10 + 0) % A;
		int y = (r * 10 + 1) % A;
		if (last_rem[x] == -1) {
			last_rem[x] = r;
			choice[x] = 0;
			q.push(x);
		}
		if (last_rem[y] == -1) {
			last_rem[y] = r;
			choice[y] = 1;
			q.push(y);
		}
	}
	string num = "";
	int rem = 0;
	while (rem != 1) {
		num += choice[rem] + '0';
		rem = last_rem[rem];
	}
	num += '1';
	return string(num.rbegin(), num.rend());
}
int main() {
	int n;
	cin >> n;
	cout << multiple(n) << endl;
}
// int calculaterem(int digits, int no, int A) {
// 	vector<int> bin(digits, 0);
// 	bin[digits - 1] = 1;

// 	int i = 0;
// 	while (no > 0) {
// 		bin[i] = no % 2;
// 		no /= 2;
// 		i++;
// 	}

// 	int rem = 0;
// 	for (auto i = bin.end() - 1; i >= bin.begin(); i--) {
// 		rem = rem * 10 + *i;
// 		rem = rem % A;
// 	}
// 	return rem;
// }
// string ans(int digits, int no) {
// 	vector<int> bin(digits, 0);
// 	bin[digits - 1] = 1;

// 	int i = 0;
// 	while (no > 0) {
// 		bin[i] = no % 2;
// 		no /= 2;
// 		i++;
// 	}
// 	string num = "";
// 	for (auto i = bin.end() - 1; i >= bin.begin(); i--) {
// 		num += *i + '0';
// 	}
// 	return num;
// }
// string multiple(int N) {
// 	queue<pair<int, int>> q;
// 	q.push({1, 0});
// 	pair<int, int> curr;
// 	long long int num = 0;
// 	int rem;
// 	vector<int> visited(N, -1);
// 	while (1) {
// 		curr = q.front(); q.pop();
// 		rem = calculaterem(curr.first, curr.second, N);
// 		// cout << curr.first << "," << curr.second << endl;
// 		// cout << rem << "->";
// 		if (rem == 0) break;
// 		if (visited[rem] == -1) {
// 			visited[rem] = 0;
// 			q.push({curr.first + 1, curr.second * 2});
// 			q.push({curr.first + 1, curr.second * 2 + 1});
// 		}
// 	}
// 	return ans(curr.first, curr.second);
// }