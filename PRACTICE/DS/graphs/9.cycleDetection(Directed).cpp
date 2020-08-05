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

	bool isCyclicHelper(T node, map<T, bool> &visited, map<T, bool> &inStack) {

		//Processing the current node- visited, instack
		visited[node] = true;
		inStack[node] = true;

		//Explore the neighbours
		for (T neighbour : adjList[node]) {
			//We return true if
			//1. The current node is not visited but its further branch is leading to a cycle
			//2. OR the next node is present in stack
			// if ( ( !visited[neighbour] && isCyclicHelper(neighbour, visited, inStack) ) || inStack[neighbour] )
			// 	return true;

			if (inStack[neighbour]) {
				return true;
			}
			if (!visited[neighbour]) {
				if (isCyclicHelper(neighbour, visited, inStack))
					return true;
			}

		}
		//Going to popout the node from the stack
		inStack[node] = false;
		return false;
	}
	bool isCyclic() {
		//map bydeafult has false values
		map<T, bool> visited;
		map<T, bool> inStack;

		//To check the cycle in each dfs tree
		for (auto i : adjList) {
			T node = i.first;
			if (!visited[node])
				if (isCyclicHelper(node, visited, inStack))
					return true;
		}
		return false;
	}
};

int main() {
	Graph<int> g;
	g.addEdge(0, 2, false);
	g.addEdge(0, 1, false);
	g.addEdge(2, 3, false);
	g.addEdge(2, 4, false);
	// g.addEdge(3, 0, false);
	g.addEdge(4, 5, false);
	g.addEdge(1, 5, false);

	if (g.isCyclic())
		cout << "CYCLE PRESENT";
	else
		cout << "CYCLE NOT PRESENT";
}