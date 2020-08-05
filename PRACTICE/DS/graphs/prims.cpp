#include<bits/stdc++.h>
using namespace std;
void printOutput(int* parent, int* weights, int n) {
	for (int i = 1; i < n; i++) { //we have to print n-1 edges, starting with 1 bcz parent of 0 is -1
		if (i < parent[i]) {
			cout << i << " " << parent[i] << " " << weights[i] << endl;
		} else {
			cout << parent[i] << " " << i << " " << weights[i] << endl;
		}
	}
}

//TODO: optimize using priority queue
int getMinVertex(bool* visited, int* weights, int n) {
	int minVertex = -1;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex])) {
			minVertex = i;
		}
	}
	return minVertex;
}

//TODO: optimize using adjacency list
void prims(int**edges, int n) {
	bool *visited = new bool[n]();
	int *weights = new int[n];
	int *parent = new int[n]; //just used for printing the output edges

	for (int i = 0; i < n; i++) {
		weights[i] = INT_MAX;
	}
	weights[0] = 0;
	parent[0] = -1;

	for (int i = 0; i < n - 1; i++) {
		//can be run n-1 times bcz if run n times,no harm in running n times
		//nth iteration will chose last vertex which is already included in an edge from previous vertex

		//Find Min Vertex i.e. unvisited vertex with min weight
		int minVertex = getMinVertex(visited, weights, n);
		visited[minVertex] = true;

		//Explore unvisited neighbours & update accordingly
		for (int j = 0; j < n; j++) {
			if (edges[minVertex][j] != 0 && !visited[j]) {
				if (edges[minVertex][j] < weights[j]) {
					weights[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	}
	printOutput(parent, weights, n);

	delete[] visited;
	delete[] weights;
	delete[] parent;
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
	prims(edges, n);

	for (int i = 0; i < n; i++) {
		delete[] edges[i];
	}
	delete[] edges;
}