#include <bits/stdc++.h>
using namespace std;
class city {
public:
	int x;
	int y;
	int f;
};
int main() {
	int n; cin >> n;
	vector<city> cities(n);
	for (int i = 0; i < n; i++)
		cin >> cities[i].x >> cities[i].y >> cities[i].f;

	vector<double> dp(n);
	dp[0] = cities[0].f;
	for (int i = 1; i < n; i++) {
		dp[i] = -1e9;
		int x1 = cities[i].x, y1 = cities[i].y;
		for (int j = i - 1; j >= 0; j--) {
			int x2 = cities[j].x, y2 = cities[j].y;
			double dis = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
			double temp = dp[j] + cities[i].f - dis;
			dp[i] = max(dp[i], temp);
		}
	}
	cout << fixed << setprecision(6) << dp[n - 1] << endl;
}