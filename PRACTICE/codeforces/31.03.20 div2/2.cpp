#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define w(x) int x; cin>>x; while(x--)
#define endl "\n"
#define int long long

int32_t main() {
	IOS;
	vector<int> prm = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
	w(t) {
		int n; cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		vector<int> output(n, -1);
		int color = 1;
		for (int i = 0; i < prm.size(); i++) {
			bool got = 0;

			for (int j = 0; j < n; j++) {
				//not divisible by this prime
				if (v[j] % prm[i] != 0) continue;
				//has been colored
				if (output[j] != -1)continue;

				//color it now
				got = 1;
				output[j] = color;
			}

			if (got) color++;
		}

		cout << color - 1 << endl;
		for (int i = 0; i < n; i++) {
			cout << output[i] << " ";
		}
		cout << endl;
	}
	return 0;
}