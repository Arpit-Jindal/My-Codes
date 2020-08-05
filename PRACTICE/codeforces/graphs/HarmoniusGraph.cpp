// https://codeforces.com/problemset/problem/1253/D

//USING DSU IMPLEMENTATION OF CODEFORCES
#include<bits/stdc++.h>
using namespace std;
class DSU {
public:
	vector<int> parent;
	vector<int> maxVal;
	DSU(int n): parent(n), maxVal(n) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			maxVal[i] = i;
		}
	}
	void join(int a, int b) {
		int pb = find(b);
		int pa = find(a);
		parent[pb] = pa;
		maxVal[pa] = max(maxVal[pb], maxVal[pa]);
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
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int M = dsu.maxVal[dsu.find(i)];
		int src = i;
		for (; i < M; i++) {
			if (!dsu.check(src, i)) {
				ans++;
				dsu.join(src, i);
				M = max(M, dsu.maxVal[dsu.find(src)]);
			}
		}
	}
	cout << ans;
}


//USING DSU IMPLEMENTAION OF Struct (gfg)
#include<bits/stdc++.h>
using namespace std;
struct disjSet {
	int parent;
	int maxval;
};
disjSet* makeSet(int n) {
	disjSet* DJ = new disjSet[n + 1];
	for (int i = 1; i <= n; i++) {
		DJ[i].parent = i;
		DJ[i].maxval = i;
	}
	return DJ;
}
int find(disjSet* DJ, int x) {
	if (DJ[x].parent != x) {
		DJ[x].parent = find(DJ, DJ[x].parent);
	}
	return DJ[x].parent;
}
void Union(disjSet* DJ, int x, int y) {
	int xParent = find(DJ, x);
	int yParent = find(DJ, y);
	DJ[xParent].maxval = max(DJ[xParent].maxval, DJ[yParent].maxval);
	DJ[yParent].parent = xParent;
}
int main() {
	int n, m;
	cin >> n >> m;
	disjSet* DJ = makeSet(n);
	for (int i = 0; i < m; i++) {
		int f, s; cin >> f >> s;
		Union(DJ, f, s);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int m = DJ[find(DJ, i)].maxval;
		int src = i;
		for (; i < m; i++) {
			if (find(DJ, src) != find(DJ, i)) {
				Union(DJ, i, src);
				m = max(m, DJ[find(DJ, i)].maxval);
				ans++;
			}
		}
	}
	cout << ans;
}
