#include<bits/stdc++.h>
using namespace std;
//TODO: optimize using priority queue
int getMinVertex(bool* visited, int *distances, int n) {
	int minVertex = -1;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && (minVertex == -1 || distances[minVertex] > distances[i])) {
			minVertex = i;
		}
	}
	return minVertex;
}
//TODO: optimize using adjacency list
void dijkstra(int **edges, int n, int src) {
	bool* visited = new bool[n]();
	int* distances = new int[n];

	for (int i = 0; i < n; i++) distances[i] = INT_MAX;
	distances[src] = 0;

	for (int i = 0; i < n - 1; i++) {
		int minVertex = getMinVertex(visited, distances, n);
		visited[minVertex] = true;
		for (int j = 0; j < n; j++) {
			if (edges[minVertex][j] != 0 && !visited[j]) {
				int tempDist = distances[minVertex] + edges[minVertex][j];
				if (tempDist < distances[j]) {
					distances[j] = tempDist;
				}
			}
		}
	}
	cout << "Distance of all vertices from 0: \n";
	for (int i = 0; i < n; i++) {
		cout << i << " " << distances[i] << endl;
	}
	delete[] visited;
	delete[] distances;
}

int main() {
	int n, E;
	cin >> n >> E;
	int **edges = new int*[n];
	for (int i = 0; i < n; i++) {
		edges[i] = new int[n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}
	for (int i = 0; i < E; i++) {
		int f, s, w;
		cin >> f >> s >> w;
		edges[f][s] = w;
		edges[s][f] = w;
	}
	dijkstra(edges, n, 0);

	for (int i = 0; i < n; i++) {
		delete[] edges[i];
	}
	delete[] edges;
}