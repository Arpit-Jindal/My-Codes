#include<iostream>
#include<list>
#include<map>
using namespace std;
template<typename T>
class Graph {
	map<T, list<T>> adjList;
public:
	Graph() { }
	void addEdge(T u, T v, bool bidir = true) {
		adjList[u].push_back(v);
		if (bidir)
			adjList[v].push_back(u);
	}
	void dfshelper(T node, map<T, bool> &visited, list<T> &ordering) {
		visited[node] = true;

		//Call dfs on unvisited neighbours of current node
		for (T neighbour : adjList[node]) {
			if (!visited[neighbour]) {
				dfshelper(neighbour, visited, ordering);
			}
		}

		//At this point all the children of the current node have been visited
		//so we can add current node to the list
		ordering.push_front(node);
	}
	void dfsTopologicalSort() {
		map<T, bool> visited;
		list<T> ordering;
		for (auto i : adjList) {
			//i is a pair (node,list of nodes)
			T node = i.first;
			if (!visited[node]) {
				dfshelper(node, visited, ordering);
			}
		}
		//Print all the elements
		for (T element : ordering) {
			cout << element << "-->";
		}
	}
};
int main() {
	Graph<string> G;
	G.addEdge("English", "Programming Language", false);
	G.addEdge("Maths", "Programming Language", false);
	G.addEdge("Programming Language", "HTML", false);
	G.addEdge("Programming Language", "Python", false);
	G.addEdge("Programming Language", "Java", false);
	G.addEdge("Programming Language", "JS", false);
	G.addEdge("Python", "WebD", false);
	G.addEdge("HTML", "CSS", false);
	G.addEdge("CSS", "JS", false);
	G.addEdge("JS", "WebD", false);
	G.addEdge("Java", "WebD", false);
	G.dfsTopologicalSort();
}