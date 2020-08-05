#include <bits/stdc++.h>
using namespace std;
class Edge {
public:
  int source;
  int dest;
  int weight;
};
class disjSet {
public:
  int parent;
  int rank;
};
int compare(Edge e1, Edge e2) {
  return e1.weight < e2.weight;
}
int find(disjSet* DJ, int i) {
  if (DJ[i].parent != i) {
    DJ[i].parent = find(DJ, DJ[i].parent);
  }
  return DJ[i].parent;
}
void Union(disjSet* DJ, int x, int y) {
  int xRoot = find(DJ, x);
  int yRoot = find(DJ, y);
  if (DJ[xRoot].rank > DJ[yRoot].rank) {
    DJ[yRoot].parent = xRoot;
  } else if (DJ[xRoot].rank < DJ[yRoot].rank) {
    DJ[xRoot].parent = yRoot;
  } else {
    DJ[yRoot].parent = xRoot;
    DJ[xRoot].rank++;
  }
}
disjSet* makeSet (int n) {
  disjSet* DJ = new disjSet[n];
  for (int i = 0; i < n; i++) {
    DJ[i].parent = i;
    DJ[i].rank = 0;
  }
  return DJ;
}
bool hasCycle(Edge *graph, DisjSet *ds, int n, int m)
{
  sort(graph, graph + m, compare);
  for (int i = 0; i < m; i++) {
    int x = find(ds, graph[i].start);
    int y = find(ds, graph[i].dest);
    if (x == y)
      return true;
    Union(ds, x, y);
  }
}

int main()
{
  int n, E; //n->no of vertices, E->no of Edges
  cin >> n >> E;
  Edge* graph = new Edge[E];
  for (int i = 0; i < E; i++) {
    int s, d, w;
    cin >> s >> d >> w;
    graph[i].source = s;
    graph[i].dest = d;
    graph[i].weight = w;
  }

  DisjSet *ds = makeSet(n);
  cout << "\nThe Graph Has Cycle: " << hasCycle(graph, ds, n, m) << endl;
}