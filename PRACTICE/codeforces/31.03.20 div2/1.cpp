//https://codeforces.com/contest/1332/problem/A
#include<iostream>
using namespace std;
#define IOS ios::sync_with_stdio(0);
#define endl "\n"
#define int long long
int32_t main() {
	IOS;
	int t; cin >> t;
	while (t--) {
		int l, r, d, u; cin >> l >> r >> d >> u;
		int x, y, xl, yd, xr, yu; cin >> x >> y >> xl >> yd >> xr >> yu;
		int ans = 1;

		//Out of bounds
		if (l - r > x - xl || r - l > xr - x) ans = 0;
		if (u - d > yu - y || d - u > y - yd) ans = 0;

		//Not even 1 place to move
		if (xl == xr && (l + r) > 0) ans = 0;
		if (yu == yd && (u + d) > 0) ans = 0;
		if (ans) cout << "Yes\n";
		else cout << "No\n";
	}
}
// int32_t main() {
// 	IOS;
// 	int t; cin >> t;
// 	while (t--) {
// 		int a, b, c, d; cin >> a >> b >> c >> d;
// 		int x, y, x1, y1, x2, y2; cin >> x >> y >> x1 >> y1 >> x2 >> y2;

// 		//No space for even 1 step
// 		if (b > 0 && b == a) {
// 			if ((x - 1 < x1 || x - 1 > x2) && (x + 1 < x1 || x + 1 > x2)) {
// 				cout << "No" << endl;
// 				continue;
// 			}
// 		}
// 		if (c > 0 && c == d) {
// 			if ((y - 1 < y1 || y - 1 > y2) && (y + 1 < y1 || y + 1 > y2)) {
// 				cout << "No" << endl;
// 				continue;
// 			}
// 		}

// 		//Checking for final position
// 		int r = x - a + b;
// 		int s = y - c + d;

// 		if (r < x1 || r > x2 || s < y1 || s > y2) {
// 			cout << "No" << endl;
// 		}
// 		else {
// 			cout << "Yes" << endl;
// 		}
// 	}
// 	return 0;
// }