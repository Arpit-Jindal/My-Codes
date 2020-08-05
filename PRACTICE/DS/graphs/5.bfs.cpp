//Breadth first Search - Level Order Traversal - Iterative method
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<climits>
using namespace std;
template<typename T>
class Graph
{
	map<T, list<T>> adjList;
public:
	Graph() { }
	void addEdge(T u, T v, bool bidir = true)
	{
		adjList[u].push_back(v);
		if (bidir) adjList[v].push_back(u);
	}
	void print()
	{
		for (auto i : adjList)
		{
			cout << i.first << "->";
			for (auto entry : i.second) //auto here is T
				cout << entry << ",";
			cout << endl;
		}
	}
	void bfs(T src)
	{
		queue<T> q;
		map<T, bool> visited;
		q.push(src);
		visited[src] = true;
		while (!q.empty())
		{
			T node = q.front(); q.pop();
			cout << node << ",";
			for (int neighbour : adjList[node])
			{
				if (!visited[neighbour])
				{
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}
	void bfs_shortest_path(T src) // SSSP(Single Source Shortest Path)
	{
		queue<T> q;
		map<T, int> distance;
		// map<T, T> parent;

		for (auto i : adjList)
			distance[i.first] = INT_MAX;

		q.push(src);
		distance[src] = 0;
		// parent[src] = src;

		while (!q.empty())
		{
			T node = q.front(); q.pop();
			cout << node << ",";
			for (auto neighbour : adjList[node])
			{
				if (distance[neighbour] == INT_MAX)
				{
					q.push(neighbour);
					distance[neighbour] = distance[node] + 1;
					// parent[neighbour] = node;
				}
			}
		}
		//Print the distances for all the nodes
		for (auto i : distance)
			cout << "\nDistance of " << i.first << " from " << src << " is " << i.second;
	}
};
int main()
{
	Graph<int> G;
	G.addEdge(0, 1);
	G.addEdge(1, 2);
	G.addEdge(0, 4);
	G.addEdge(2, 4);
	G.addEdge(2, 3);
	G.addEdge(3, 5);
	G.addEdge(3, 4);
	G.bfs_shortest_path(0);
}