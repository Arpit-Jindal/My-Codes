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
	void print(){
		//iterate over the map
		for (auto i : adjList) {
			cout << i.first << "->";
			for (auto entry : i.second) //i.second is LL
				cout << entry << ",";
			cout << endl;
		}
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
	G.print();
}