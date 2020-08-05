#include<iostream>
#include<algorithm>
using namespace std;
class Edge {
public:
	int source;
	int destination;
	int weight;
};
int compare(Edge e1, Edge e2) {
	return e1.weight < e2.weight;
}
int find(int* parent, int i) {
	if (i == parent[i]) return i;
	return find(parent, parent[i]);
}
void Union(int* parent, int x, int y) {
	int xParent = find(parent, x);
	int yParent = find(parent, y);
	parent[xParent] = yParent;
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
	int* parent = new int[n];
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	while (count != n - 1) {
		int sourceParent = find(parent, input[i].source);
		int destParent  = find(parent, input[i].destination);
		if (sourceParent != destParent) {
			output[count] = input[i];
			count ++;
			Union(parent, input[i].source, input[i].destination);
		}
		i++;
	}
	printOutput(output, n - 1); //we have to print n-1 edges
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