#include<bits/stdc++.h>
using namespace std;
void printOutput(int* parent, int* weights, int n) {
	for (int i = 1; i < n; i++) {
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
	for (int i = 0; i < n; i++)
		if (!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex]))
			minVertex = i;
	return minVertex;
}
//comments deleted
void prims(vector<pair<int, int>> edges[], int n) {
	bool visited[n] = {0};
	int weights[n];
	memset(weights, 1e9, sizeof(weights));
	weights[0] = 0;
	for (int i = 0; i < n; i++) {
		int a = getMinVertex(visited, weights, n);
		visited[a] = true;
		for (auto p : edges[a]) {
			int neighbor = p.first;
			int dist = p.second;
			if (!visited[neighbor] && weights[neighbor] > dist)
				weights[neighbor] = dist;
		}
	}
}
void prims(vector<pair<int, int>> edges[], int n) {
	bool visited[n] = {0};
	int parent[n]; //just used for printing the output edges
	int weights[n];
	for (int i = 0; i < n; i++) {
		weights[i] = INT_MAX;
	}
	weights[0] = 0;
	parent[0] = -1;
	//This won't work as updation is not possible,inserting updated value not working as previous values still pop out and get used at some point
	// priority_queue< pair<int, int> , vector<pair<int, int> > , greater<pair<int, int> > > pq; //min pq of weight,node
	// pq.push({0, 0});
	for (int i = 0; i < n; i++) {
		// pair<int, int> minW_V = pq.top(); pq.pop();
		// int a = minW_V.second;
		int a = getMinVertex(visited, weights, n);
		visited[a] = true;
		for (int j = 0; j < edges[a].size(); j++) {
			pair<int, int> p = edges[a][j];
			int dist = p.second;
			int neighbor = p.first;
			if (!visited[neighbor] && weights[neighbor] > dist) {
				weights[neighbor] = dist;
				parent[neighbor] = a;
				// pq.push({dist, neighbor});
			}
		}
	}
	printOutput(parent, weights, n);
}
int main() {
	int n, E ;
	cin >> n >> E;
	//using array of vectors as graph instead of unordered_map<int,pair<int,int>>
	vector<pair<int, int>> edges[n];
	for (int i = 0; i < E; i++) {
		int f, s, w;
		cin >> f >> s >> w;
		edges[f].push_back({s, w});
		edges[s].push_back({f, w});
	}
	prims(edges, n);
}
/* input
5 7
0 1 4
0 2 8
1 3 6
1 2 2
2 3 3
2 4 9
3 4 5
*/