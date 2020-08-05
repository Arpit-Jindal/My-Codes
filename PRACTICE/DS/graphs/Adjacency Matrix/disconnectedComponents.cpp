#include<iostream>
#include<queue>
using namespace std;
void printdfs(int **edges, int v, bool* visited, int sv) {
	cout << sv << "->";
	visited[sv] = true;
	for (int i = 0; i < v; i++) {
		if (!visited[i]&& edges[sv][i]) {
			printdfs(edges, v, visited, i);
		}
	}
}
void printbfs(int **edges, int v, bool* visited, int sv) {
	queue<int> q;
	q.push(sv);
	visited[sv] = true;
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		cout << current << "->";
		for (int i = 0; i < v; i++) {
			if (!visited[i] && edges[current][i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}
void DFS(int **edges, int v) {
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < v; i++) {
		if (!visited[i])
			printdfs(edges, v, visited, i);
	}
	delete[] visited;
	cout<<endl;
}
void BFS(int **edges, int v) {
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < v; i++) {
		if (!visited[i])
			printbfs(edges, v, visited, i);
	}
	delete[] visited;
	cout<<endl;
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
	cout<<"BFS: ";
	BFS(edges, v);
	cout<<"DFS: ";
	DFS(edges, v);
	for (int i = 0; i < v; i++) {
		delete[] edges[i];
	}
	delete[] edges;
}