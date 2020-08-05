//KOSARAJU ALGORITHM - STRONGLY CONNECTED COMPONENTS
#include<bits/stdc++.h>
using namespace std;

//why 0 is not considered when we pass g by reference ??????????????????????????????????????????????????????????????
void dfs1(unordered_map<int, vector<int>> g, int node, unordered_map<int, bool> &visited, stack<int> &finishedVertices) {
	visited[node] = true;
	for (int neighbour : g[node]) {
		if (!visited[neighbour]) {
			dfs1(g, neighbour, visited, finishedVertices);
		}
	}
	finishedVertices.push(node);
}
void dfs2(unordered_map<int, vector<int>> gT, int node, unordered_map<int, bool> &visited, vector<int> &v) {
	visited[node] = true;
	v.push_back(node);
	for (int neighbour : gT[node]) {
		if (!visited[neighbour]) {
			dfs2(gT, neighbour, visited, v);
		}
	}
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

	//We have our stack filled now
	visited.clear();
	vector<vector<int>> ans;

	while (!finishedVertices.empty()) {
		int node = finishedVertices.top();
		finishedVertices.pop();
		if (!visited[node]) {
			vector<int> v;
			dfs2(gT, node, visited, v);
			ans.push_back(v);
		}
	}
	return ans;
}
void printConnectedComponents(vector<vector<int>> v) {
	for ( auto i : v) {
		for (auto j : i) {
			cout << j + 1 << " ";
		}
		cout << endl;
	}
}
int main() {
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
	vector<vector<int>> v = getSCC(g, gT);
	printConnectedComponents(v);
}

/* input
6
7
1 2
2 3
3 4
4 1
3 5
5 6
6 5


10
12
1 2
2 3
3 4
4 1
3 5
5 6
6 7
7 5
8 6
8 9
9 8
9 10

8 8
1 2
2 3
3 4
4 1
4 5
6 5
6 7
6 8

5 4
1 2
3 2
3 4
3 5
*/