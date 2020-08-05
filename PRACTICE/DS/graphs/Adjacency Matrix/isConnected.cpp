#include<iostream>
#include<queue>
using namespace std;
void dfs(int **edges, int v, bool* visited, int sv) {
	visited[sv] = true;
	for (int i = 0; i < v; i++) {
		if (visited[i] == false && edges[sv][i] == 1) {
			dfs(edges, v, visited, i);
		}
	}
}
void bfs(int **edges, int v, bool* visited, int sv) {
	queue<int> q;
	q.push(sv);
	visited[sv] = true;
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < v; i++) {
			if (!visited[i] && edges[current][i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}
int isConnectedDFS(int **edges, int v) {
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}
	dfs(edges, v, visited, 0);
	for (int i = 0; i < v; i++) {
		if (!visited[i])
			return 0; //disconnected
	}
	delete[] visited;
	return 1; //connected
}
int isConnectedBFS(int **edges, int v) {
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}
	bfs(edges, v, visited, 0);
	for (int i = 0; i < v; i++) {
		if (!visited[i])
			return 0; //disconnected
	}
	delete[] visited;
	return 1; //connected
}
int main() {
	int v, e;
	cin >> v >> e;
	int **edges = new int*[v];
	for (int i = 0; i < v; i++) {
		edges[i] = new int[v];
		for (int j = 0; j < v; j++) {
			edges[i][j] = 0;
		}
	}
	int f, s;
	for (int i = 0; i < e; i++) {
		cin >> f >> s;
		edges[f][s] = edges[s][f] = 1;
	}
	cout << "BFS: " << isConnectedBFS(edges, v) << endl;
	cout << "DFS: " << isConnectedDFS(edges, v) << endl;
	for (int i = 0; i < v; i++) {
		delete[] edges[i];
	}
	delete[] edges;
}