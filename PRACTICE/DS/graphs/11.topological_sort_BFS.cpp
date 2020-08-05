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
		if (bidir) adjList[v].push_back(u);
	}
	void bfsTopologicalSort(){
		queue<T> q; //use prority queue if output is to be sorted in some order
		map<T,int> indegree;

		//Initialise indegree of all nodes
		for(auto i:adjList){
			T u = i.first;
			for(T v:adjList[u])
				indegree[v]++;
		}
		//Find out all nodes with 0 indegree
		for(auto i:adjList){
			T u = i.first;
			if(indegree[u] == 0) q.push(u);
		}
		//Start with algorithm
		while(!q.empty())
		{
			T node = q.front(); q.pop();
			cout<<node<<"-->";
			for(T neighbour: adjList[node])
			{
				indegree[neighbour]--;
				if(indegree[neighbour] == 0)
					q.push(neighbour);
			}
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
	G.addEdge("HTML", "JS", false);
	G.addEdge("JS", "WebD", false);
	G.addEdge("Java", "WebD", false);
	G.bfsTopologicalSort();
}