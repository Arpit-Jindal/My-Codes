#include<iostream>
#include<list>
#include<map>
#include <queue>
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
	bool isCyclicBFS(T src) {
		queue<T> q;
		map<T, bool> visited;
		map<T, T> parent;

		q.push(src);
		visited[src] = true;
		parent[src] = src;

		while (!q.empty())
		{
			T node = q.front(); q.pop();
			//Iterate over neighbours of that node
			for (auto neighbour : adjList[node]) {

				if (visited[neighbour] && parent[node] != neighbour)
					return true;

				if (!visited[neighbour]) {
					visited[neighbour] = true;
					parent[neighbour] = node;
					q.push(neighbour);
				}
			}
		}
		return false;
	}
	bool isCyclicDFSHelper(map<T, bool> &visited, T node, map<T, T> &parent) {
		for (auto neighbour : adjList[node]) {
			if (visited[neighbour] && parent[node] != neighbour)
				return true;

			if (!visited[neighbour]) {
				visited[neighbour] = true;
				parent[neighbour] = node;
				if (isCyclicDFSHelper(visited, neighbour, parent))
					return true;
			}
		}
		return false;
	}
	bool isCyclicDFS() {
		map<T, bool> visited;
		map<T, T> parent;

		// To check the cycle in each dfs tree
		for (auto i : adjList) {
			T node = i.first;
			if (!visited[node]) {
				parent[node] = node;
				visited[node] = true;
				if (isCyclicDFSHelper(visited, node, parent))
					return true;
			}
		}
		return false;
	}
};
int main() {
	Graph<int> G;
	G.addEdge(1, 2);
	G.addEdge(1, 4);
	G.addEdge(4, 3);
	G.addEdge(2, 3);

	cout << G.isCyclicBFS(1) << endl;
	cout << G.isCyclicDFS() << endl;
}