#include<bits/stdc++.h>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};
//DFS
void dfs(UndirectedGraphNode *node, map<UndirectedGraphNode*, UndirectedGraphNode*> &newgraph) {
	newgraph[node] = new UndirectedGraphNode(node->label);
	for (auto i : node->neighbors) {
		if (newgraph.find(i) == newgraph.end())
			dfs(i, newgraph);
		newgraph[node]->neighbors.push_back(newgraph[i]);
	}
}
UndirectedGraphNode cloneGraph(UndirectedGraphNode *node) {
	map<UndirectedGraphNode*, UndirectedGraphNode*> newgraph;
	dfs(node, newgraph);
	return newgraph[node];
}
//BFS
UndirectedGraphNode* cloneGraph(UndirectedGraphNode * node) {
	queue<UndirectedGraphNode*> q;
	q.push(node);
	map<UndirectedGraphNode*, UndirectedGraphNode*> newgraph;
	while (!q.empty()) {
		UndirectedGraphNode* curr = q.front(); q.pop();
		if (newgraph.find(curr) == newgraph.end()) {
			newgraph[curr] = new UndirectedGraphNode(curr->label);
		}
		for (auto neighbor : curr->neighbors) {
			if (newgraph.find(neighbor) == newgraph.end()) {
				q.push(neighbor);
				newgraph[neighbor] = new UndirectedGraphNode(neighbor->label);
			}
			(newgraph[curr]->neighbors).push_back(newgraph[neighbor]);
		}
	}
	return newgraph[node];
}
int main() {
	UndirectedGraphNode* node1 = new UndirectedGraphNode(703);
	UndirectedGraphNode* node2 = new UndirectedGraphNode(43);
	UndirectedGraphNode* node3 = new UndirectedGraphNode(279);
	node1->neighbors = {node2, node3, node1};
	node2->neighbors = {node3, node1};
	node3->neighbors = {node2, node3, node1};
	UndirectedGraphNode* node = cloneGraph(node1);
	// cout << node->label;
}