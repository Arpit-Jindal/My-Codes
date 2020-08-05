//Depth first Search
#include<iostream>
#include<list>
#include<map>
using namespace std;
template<typename T>
class Graph {
	map<T, list<T>> adjList;
public:
	Graph() { }
	void addEdge(T u, T v, bool bidir = true)
	{
		adjList[u].push_back(v);
		if (bidir)
			adjList[v].push_back(u);
	}
	void dfshelper(T node, map<T, bool> &visited)
	{
		//Whenever you come to a node mark it as visited
		visited[node] = true;
		cout << node << " ";

		//Try to find the unvisited neighbour
		for (T neighbour : adjList[node])
			if (!visited[neighbour])
				dfshelper(neighbour, visited);
	}
	void dfs(T src)
	{
		map<T, bool> visited; // All the values are false by default
		dfshelper(src, visited);

		//connected components
		int component = 1;
		cout << endl;
		for (auto i : adjList)
		{
			T city = i.first;
			if (!visited[city]) {
				dfshelper(city, visited);
				component++;
			}
		}
		cout << "\nThe current Graph has " << component << " components";
	}
};
int main() {
	Graph<int> G;
	G.addEdge(0, 1);
	G.addEdge(1, 2);
	G.addEdge(0, 4);
	G.addEdge(2, 4);
	G.addEdge(2, 3);
	G.addEdge(3, 5);
	G.addEdge(3, 4);
	G.addEdge(6, 7);
	G.dfs(0);
}