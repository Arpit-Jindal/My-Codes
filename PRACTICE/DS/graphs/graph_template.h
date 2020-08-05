#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph
{
	unordered_map<T, vector<T>> adjList;
public:
	Graph() { }
	void addEdge(T u, T v, bool bidir = true)
	{
		adjList[u].push_back(v);
		if (bidir)
			adjList[v].push_back(u);
	}
	void print()
	{
		for (auto i : adjList) //auto = pair<T,vector<T>>
		{
			cout << i.first << "->";
			for (auto entry : i.second) //auto = T //i.second is vector
				cout << entry << ",";
			cout << endl;
		}
	}
	void dfshelper(T node, unordered_map<T, bool> &visited, vector<T> &v)
	{
		visited[node] = true;
		v.push_back(node);
		for (T neighbour : adjList[node])
			if (!visited[neighbour])
				dfshelper(neighbour, visited, v);
	}
	vector<vector<T>> getConnectedComponents() {
		unordered_map<T, bool> visited;
		vector<vector<T>> ans;
		for (auto i : adjList) {
			T node = i.first;
			if (!visited[node]) {
				vector<T> v;
				dfshelper(node, visited, v);
				ans.push_back(v);
			}
		}
		return ans;
	}
	void printConnectedComponents(vector<vector<T>> v) {
		for ( auto i : v) {
			for (auto j : i) {
				cout << j << " ";
			}
			cout << endl;
		}
	}
	int getSize() {
		return adjList.size();
	}
};