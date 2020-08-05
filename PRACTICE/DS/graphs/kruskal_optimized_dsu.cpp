#include<bits/stdc++.h>
using namespace std;
class Edge {
public:
	int source;
	int destination;
	int weight;
};
class DSU {
public:
	vector<int> parent;
	DSU(int n): parent(n) {
		for (int i = 0; i < n; i++) parent[i] = i;
	}
	void join(int a, int b) {
		parent[find(b)] = find(a);
	}
	int find(int a) {
		return a == parent[a] ? a : parent[a] = find(parent[a]);
	}
	bool check(int a, int b) {
		return find(a) == find(b);
	}
};
int compare(Edge e1, Edge e2) {
	return e1.weight < e2.weight;
}
void printOutput(Edge* output, int n) {
	for (int i = 0; i < n; i++) {
		if (output[i].source < output[i].destination) {
			cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
		} else {
			cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl;
		}
	}
}
void kruskal (Edge* input, int n, int E) {

	//1. sort the input array based on weights
	sort(input, input + E, compare);

	//2. Initialise the output array
	Edge* output = new Edge[n - 1];

	//3. maintain count of edges to be added in output - also iterator of output array
	int count = 0;

	//4. iterator over input array
	int i = 0;

	//5. union find array
	DSU dj(n);

	while (count != n - 1) {
		if (dj.check(input[i].source, input[i].destination) == false) {
			output[count++] = input[i];
			dj.join(input[i].source, input[i].destination);
		}
		i++;
	}
	printOutput(output, n - 1);
}
int main() {
	int n, E; //n->no of vertices, E->no of Edges
	cin >> n >> E;
	Edge* input = new Edge[E];
	for (int i = 0; i < E; i++) {
		int s, d, w;
		cin >> s >> d >> w;
		input[i].source = s;
		input[i].destination = d;
		input[i].weight = w;
	}
	kruskal(input, n, E);
}