#include<bits/stdc++.h>
using namespace std;
void dfs1(unordered_map<int, vector<int>> g, int node, unordered_map<int, bool> &visited, stack<int> &finishedVertices) {
	visited[node] = true;
	for (int neighbour : g[node])
		if (!visited[neighbour])
			dfs1(g, neighbour, visited, finishedVertices);
	finishedVertices.push(node);
}
void dfs2(unordered_map<int, vector<int>> gT, int node, unordered_map<int, bool> &visited) {
	visited[node] = true;
	for (int neighbour : gT[node])
		if (!visited[neighbour])
			dfs2(gT, neighbour, visited, v);
}
vector<vector<int>> getSCC(unordered_map<int, vector<int>>& g, unordered_map<int, vector<int>>& gT) {
	stack<int> finishedVertices;
	unordered_map<int, bool> visited;
	for (auto i : g) {
		int node = i.first;
		if (!visited[node]) {
			dfs1(g, node, visited, finishedVertices);
		}
	}
	visited.clear();
	int count = 0;
	while (!finishedVertices.empty()) {
		int node = finishedVertices.top();
		finishedVertices.pop();
		if (!visited[node]) {
			count++;
			dfs2(gT, node, visited);
		}
	}
	return count;
}
int main() {
	int t; cin >> t;
	while (t--) {
		unordered_map<int, vector<int>> g;
		unordered_map<int, vector<int>> gT;
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int j, k;
			cin >> j >> k;
			g[j - 1].push_back(k - 1);
			gT[k - 1].push_back(j - 1);
		}
		cout << getCount(g, gT) << endl;
	}
}
/* input
1
3 2
1 2
2 3
*/