#include<iostream>
#include<vector>
using namespace std;
#define IOS ios::sync_with_stdio(0);
#define endl "\n"
#define int long long
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int32_t main() {
	IOS;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].first;
			v[i].second = 0;
		}
		int m = 0;
		for (int i = 0; i < n; i++) {
			if (v[i].second == 0) {
				++m;
				v[i].second = m;
				for (int j = i + 1; j < n; j++) {
					if (v[j].second == 0) {
						int GCD = gcd(v[i].first, v[j].first);
						if (GCD > 1) {
							v[j].second = v[i].second;
						}
					}
				}
			}
			else {
				for (int j = i + 1; j < n; j++) {
					if (v[j].second == v[i].second) {
						if (gcd(v[i].first, v[j].first) <= 1) {
							++m;
							v[j].second = m;
						}
					}
				}
			}
		}
		cout << m << endl;
		for (int i = 0; i < n; i++) {
			cout << v[i].first << "->";
			cout << v[i].second << "\n";
		}
		cout << endl;
	}
	return 0;
}