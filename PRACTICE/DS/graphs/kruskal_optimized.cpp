#include<iostream>
#include<algorithm>
using namespace std;
class Edge {
public:
	int source;
	int destination;
	int weight;
};
class disjSet {
public:
	int parent;
	int rank;
};
int compare(Edge e1, Edge e2) {
	return e1.weight < e2.weight;
}
int find(disjSet* DJ, int i) {
	if (DJ[i].parent != i) {
		DJ[i].parent = find(DJ, DJ[i].parent);
	}
	return DJ[i].parent;
}
void Union(disjSet* DJ, int x, int y) {
	int xRoot = find(DJ, x);
	int yRoot = find(DJ, y);
	if (DJ[xRoot].rank > DJ[yRoot].rank) {
		DJ[yRoot].parent = xRoot;
	} else if (DJ[xRoot].rank < DJ[yRoot].rank) {
		DJ[xRoot].parent = yRoot;
	} else {
		DJ[yRoot].parent = xRoot;
		DJ[xRoot].rank++;
	}
}
disjSet* makeSet (int n) {
	disjSet* DJ = new disjSet[n];
	for (int i = 0; i < n; i++) {
		DJ[i].parent = i;
		DJ[i].rank = 0;
	}
	return DJ;
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
	disjSet* DJ = makeSet(n);

	while (count != n - 1) {
		int sourceParent = find(DJ, input[i].source);
		int destParent  = find(DJ, input[i].destination);
		if (sourceParent != destParent) {
			output[count] = input[i];
			count ++;
			Union(DJ, input[i].source, input[i].destination);
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