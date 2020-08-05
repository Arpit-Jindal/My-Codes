#include<bits/stdc++.h>
using namespace std;
void dfs(int **graph, int V, int n, int start, int vert, int& count, bool* visited) {
	if (n == 0) {
		if (graph[start][vert]) {
			count++;
		}
		return;
	}
	visited[vert] = true;
	for (int i = 0; i < V; i++) {
		if (!visited[i] && graph[vert][i]) {
			dfs(graph, V, n - 1, start, i, count, visited);
		}
	}
	visited[vert] = false;
}
int countCycles(int** graph, int V, int n) {
	bool* visited = new bool[V]();
	int count = 0;
	//this calculates all the cycles in which node ith is source (or is a part of cycle)
	for (int i = 0; i < V - (n - 1); i++) {
		dfs(graph, V, n - 1, i, i, count, visited);
		visited[i] = true; //this ensures that in any cycle further this node is not included
	}
	return count / 2;
}

int main() {
	int V, m;
	cin >> V >> m;
	int *u = new int[m];
	int *v = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> u[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}
	int **graph = new int* [V];
	for (int i = 0; i < V; i++) {
		graph[i] = new int[V];
		for (int j = 0; j < V; j++) {
			graph[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		graph[u[i] - 1][v[i] - 1] = 1;
		graph[v[i] - 1][u[i] - 1] = 1;
	}
	int n; cin >> n;
	cout << "Total cycles of length " << n << " are " << countCycles(graph, V, n);
}
// input - first vertex is 1 not 0
/*
5 6
1 1 2 2 3 4
2 4 3 5 4 5
4

4 5
1 1 1 2 2
2 3 4 4 3
3

3 3
1 2 3
2 3 1
3
*/