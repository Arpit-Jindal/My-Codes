#include<iostream>
#include<queue>
using namespace std;
void bfs(int n, int m, int** edges, int* visited, int sv) {
	queue<int> q;
	q.push(sv);
	visited[sv] = true;
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if (!visited[i] && edges[current][i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}
int BFS(int n, int m, int** edges) {
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			count++;
			bfs(n, m, edges, visited, i);
		}
	}
	delete[] visited;
	return count;
}
int main() {
	int n, m;
	cin >> n >> m;
	int *u = new int[m];
	int *v = new int[n];
	for (int i = 0; i < m; i++) {
		cin >> u[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int **edges = new int* [n];
	for (int i = 0; i < n; i++) {
		edges[i] = new int[n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		edges[u[i] - 1][v[i] - 1] = 1;
	}
	cout << BFS(n, m, edges);

	for (int i = 0; i < n; i++) {
		delete[] edges[i];
	}
	delete[] edges;
	delete[] u;
	delete[] v;
}