#include<bits/stdc++.h>
using namespace std;
//BFS - prefer this over dfs
pair<int, int> bfs(vector<vector<int>> graph, int n, int src) {
	vector<int> distance(n, -1);
	distance[src] = 0;
	queue<int> q;
	q.push(src);
	//first is the node, second is the distance
	pair<int, int> maxPair = {0, 0};
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		for (auto i : graph[curr]) {
			//unvisited till now
			if (distance[i] == -1) {
				q.push(i);
				distance[i] = distance[curr] + 1;
				if (distance[i] > maxPair.second) {
					maxPair = {i, distance[i]};
				}
			}
		}
	}
	return maxPair;
}
int Solution::solve(vector<int> &A) {
	int n = A.size();
	vector<vector<int>> graph(n);
	int root = -1;
	for (int i = 0; i < n; i++) {
		if (A[i] == -1) {
			root = i;
			continue;
		}
		graph[i].push_back(A[i]);
		graph[A[i]].push_back(i);
	}

	pair<int, int> f = bfs(graph, n, root);
	pair<int, int> s = bfs(graph, n, f.first);
	return s.second;

}


//DFS
void dfs(unordered_map<int, vector<int>> &graph, int node, pair<int, int> &count, unordered_map<int, bool> &visited, unordered_map<int, int> &distance) {
	visited[node] = true;
	for (auto i : graph[node]) {
		if (!visited[i]) {
			distance[i] = distance[node] + 1;
			if (count.second < distance[i]) {
				count = {i, distance[i]};
			}
			dfs(graph, i, count, visited, distance);
		}
	}
}
int solve(vector<int> &A) {
	if (A.size() == 1) return 0;
	if (A.size() == 2) return 1;
	unordered_map<int, vector<int>> graph;
	int root = -1;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == -1) {
			root = i;
			continue;
		}
		graph[i].push_back(A[i]);
		graph[A[i]].push_back(i);
	}
	unordered_map<int, bool> visited;
	unordered_map<int, int> distance;

	visited[root] = true;
	distance[root] = 0;
	pair<int, int> count = {root, 0};
	dfs(graph, root, count, visited, distance);

	int maxCount = INT_MIN;
	int tempNode = count.first;

	distance.clear();
	visited.clear();

	for (auto i : graph[tempNode]) {
		distance[i] = 1;
		pair<int, int> count = {tempNode, 0};
		dfs(graph, i, count, visited, distance);
		maxCount = max(maxCount, count.second);
	}
	return maxCount;
}
int main() {
	vector<int> A = { -1, 0, 1, 1, 3, 0, 4, 0, 2, 8, 9, 0, 4, 6, 12, 14, 7, 9, 6, 4, 14, 13, 1, 9, 16, 17, 17, 0, 21, 10, 13, 14, 25, 28, 27, 0, 35, 20, 34, 23, 37, 3, 6, 25, 30, 22, 15, 37, 8, 6, 11, 22, 50, 12, 4, 2, 54, 23, 18, 52, 34, 49, 61, 8, 15, 63, 31, 51, 48, 41, 26, 37, 30, 15, 59, 12, 0, 40, 37, 73, 32, 19, 70, 29, 8, 21, 83, 33, 7, 13, 12, 82, 43, 86, 38, 31, 1, 84, 62, 83 };
	// vector<int> A = { -1, 0, 0, 1, 2, 1, 5, 4, 0, 8, 9, 10};
	cout << solve(A);
}