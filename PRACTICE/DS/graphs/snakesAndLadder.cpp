#include<iostream>
#include<list>
#include<map>
#include <queue>
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
		if (bidir)
			adjList[v].push_back(u);
	}
	int bfs_shortest_path(T src, T dest)
	{
		queue<T> q;
		map<T, int> distance;
		map<T, T> parent;

		for (auto i : adjList)
			distance[i.first] = INT_MAX;

		q.push(src);
		distance[src] = 0;
		parent[src] = src;

		while (!q.empty())
		{
			T temp = q.front(); q.pop();
			for (auto node : adjList[temp])
			{
				if (distance[node] == INT_MAX)
				{
					q.push(node);
					distance[node] = distance[temp] + 1;
					parent[node] = temp;
				}
			}
		}
		//start from dest and go backwards
		T path = dest;
		while (path != src)
		{
			cout << path << "<--";
			path = parent[path];
		}
		cout << src << endl;
		return distance[dest];
	}
};
int main()
{
	Graph<int> G;
	int board[50] = {0};
	board[2] = +13;
	board[5] = +2;
	board[9] = +18;
	board[18] = +11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;

	//Construct the graph
	int x, v;
	for (int u = 0; u <= 36; u++)
	{
		for (int dice = 1; dice <= 6; dice++)
		{
			x = u + dice;
			v = x + board[x];
			G.addEdge(u, v, false);
		}
	}
	int ans = G.bfs_shortest_path(1, 36);
	cout << "The shortest distance is " << ans << endl;
}