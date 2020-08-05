#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define w(x) int x; cin>>x; while(x--)
#define endl "\n"
#define int long long

int32_t main() {
	IOS;
	w(t) {
		int n, k; cin >> n >> k;
		string s; cin >> s;

		//we have to make all k length strings equal and palindrome
		int ans = 0;
		for (int i = 0; i < k / 2; i++) {
			int cnt[26] = {};
			for (int st = 0; st + k - 1 < n; st += k) {
				int i1 = st + i;
				int i2 = st + k - i - 1;
				cnt[s[i1] - 'a']++;
				cnt[s[i2] - 'a']++;
			}
			int mx = *max_element(cnt, cnt + 26);
			int req =	2 * (n / k);
			ans += req - mx;
		}
		if (k & 1) {
			int cnt[26] = {};
			for (int i = k / 2; i < n; i += k) {
				cnt[s[i] - 'a']++;
			}
			int mx = *max_element(cnt, cnt + 26);
			int req =	(n / k);
			ans += req - mx;
		}
		cout << ans << '\n';
	}
	return 0;
}