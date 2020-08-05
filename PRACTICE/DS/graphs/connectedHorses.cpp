#include<bits/stdc++.h>
#include "graph_template.h"
#define mod 1000000007
using namespace std;

long long int fact(int n) {
	long long res = 1;
	for (int i = 2; i <= n; i++)
		res *= i;
	return res;
}
void makeGraph(vector<pair<int, int>> v, int n, int m, Graph<int> &graph) {
	for (int i = 1; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		for (int j = i + 1; j < v.size(); j++) {
			if ((abs(x - v[j].first) == 1 && abs(y - v[j].second) == 2) || (abs(x - v[j].first) == 2 && abs(y - v[j].second) == 1)) {
				string f = to_string(x) + to_string(y);
				string s = to_string(v[j].first) + to_string(v[j].second);
				int first_vertex = atoi(f.c_str());
				int second_vertex = atoi(s.c_str());
				graph.addEdge(first_vertex, second_vertex);
			}
		}
	}
}
int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, q;
		cin >> n >> m >> q;
		vector<pair<int, int>> v(q + 1);
		v[0] = make_pair(INT_MIN, INT_MIN);
		for (int i = 1; i <= q; i++) {
			int x, y;
			cin >> x >> y;
			v[i] = make_pair(x, y);
		}
		Graph<int> graph;
		makeGraph(v, n, m, graph);
		vector<vector<int>> components = graph.getConnectedComponents();
		int ans = 1;
		for (auto i : components) {
			ans = (ans % mod * fact(i.size()) % mod) % mod;
		}
		cout << ans << endl;
	}
}
/* input
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4
*/