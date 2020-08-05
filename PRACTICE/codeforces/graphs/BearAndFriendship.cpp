//https://codeforces.com/problemset/problem/771/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
class DSU {
public:
	vector<int> parent;
	vector<ll> vertices;
	vector<ll> edges;
	DSU(int n): parent(n), vertices(n), edges(n) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			vertices[i] = 1;
			edges[i] = 0;
		}
	}
	void join(int a, int b) {
		int pa = find(a), pb = find(b);
		parent[pb] = pa;
		if (pa != pb) {
			vertices[pa] += vertices[pb];
			edges[pa] += edges[pb] + 1;
		}
		else {
			edges[pa]++;
		}
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
	DSU dsu(n + 1);
	for (int i = 0; i < m; i++) {
		int f, s; cin >> f >> s;
		dsu.join(f, s);
	}
	for (int i = 1; i <= n; i++) {
		if (dsu.parent[i] == i) { //a component is found
			ll reqEdges = (dsu.vertices[i] * (dsu.vertices[i] - 1)) / 2;
			if (dsu.edges[i] != reqEdges) {
				cout << "NO";
				return 0;
			}
		}
	}

	cout << "YES";
}