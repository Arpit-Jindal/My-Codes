//adjacency list implementation
#include<iostream>
#include<list>
using namespace std;
class Graph{
	int V;
	list<int> *l; // Doubly Linked List in STL
public:
	Graph(int v){
		V = v;
		l = new list<int>[V]; //array of list of integers
		// l is pointer to an array whose size is V and every object is a list of integers
	}
	void addEdge(int u, int v, bool bidir = true) //bidir = true represents undirected graph unless stated otherwise
	{
		l[u].push_back(v);
		if (bidir)
			l[v].push_back(u);
	}
	void printAdjList()
	{
		for (int i = 0; i < V; i++)
		{
			cout << i << "->";
			//L[I] is a linked list
			for (int vertex : l[i])
				cout << vertex << ",";
			cout << endl;
		}
	}
};
int main() {

	Graph g(5); // graph has 5 vertices numberes 0 to 4
	g.addEdge(0, 1);
	g.addEdge(1, 3);
	g.addEdge(0, 4);
	g.addEdge(4, 3);
	g.addEdge(1, 4);
	g.addEdge(1, 2);
	g.addEdge(2, 3);

	g.printAdjList();
}
