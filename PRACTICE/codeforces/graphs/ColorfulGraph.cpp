// https://codeforces.com/problemset/problem/505/B
#include<bits/stdc++.h>
using namespace std;

//DSU - prefer this
#define ll long long
class DSU {
public:
	vector<int> parent;
	DSU() {}
	DSU(int n): parent(n) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	void join(int a, int b) {
		parent[find(b)] = find(a);
	}
	int find(int a) {
		return a == parent[a] ? a : parent[a] = find(parent[a]);
	}
	bool check(int a, int b) {
		return find(a) == find(b);
	}
};
int main() {
	int n, m; cin >> n >> m;
	DSU d(n + 1);
	vector<DSU> dsu(m + 1);
	for (int i = 0; i <= m; i++) {
		dsu[i] = d;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		dsu[c].join(a, b);
	}
	int q; cin >> q;
	while (q--) {
		int src, dest; cin >> src >> dest;
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			if (dsu[i].check(src, dest)) ans++;
		}
		cout << ans << endl;
	}
}
//DFS
// #define int long long
// int graph[101][101][101] = {0};
// int dfs(int s, int f, int col, vector<int> &visited, int n) {
// 	if (s == f) return 1;
// 	if (visited[s]) return 0;
// 	visited[s] = 1;
// 	for (int i = 1; i <= n; i++) {
// 		if (graph[s][i][col]) {
// 			int ans = dfs(i, f, col, visited, n);
// 			if (ans) return 1;
// 		}
// 	}
// 	return 0;
// }
// int32_t main() {
// 	int n, m; cin >> n >> m;
// 	for (int i = 1; i <= m; i++) {
// 		int a, b, c; cin >> a >> b >> c;
// 		graph[a][b][c] = 1;
// 		graph[b][a][c] = 1;
// 	}
// 	int q; cin >> q;
// 	while (q--) {
// 		int s, f; cin >> s >> f;
// 		int ans = 0;
// 		for (int i = 1; i <= m; i++) {
// 			vector<int> visited(n + 1, 0);
// 			ans += dfs(s, f, i, visited, n);
// 		}
// 		cout << ans << endl;
// 	}
// }