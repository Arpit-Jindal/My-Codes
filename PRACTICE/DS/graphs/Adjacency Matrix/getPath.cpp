#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;
void getPathBFS(int **edges, int v, int sv, int ev) {
	queue<int> q;
	q.push(sv);
	bool* visited = new bool[v]();
	visited[sv] = true;
	unordered_map<int, int> m;
	bool stop = false;

	while (!q.empty() && !stop) {
		int current = q.front();
		q.pop();

		for (int i = 0; i < v; i++) {

			if (!visited[i] && edges[current][i]) {
				q.push(i);
				m[i] = current;
				visited[i] = true;

				if (i == ev) {
					stop = true;
					break;
				}
			}
		}
	}

	delete[] visited;
	vector<int> vec;
	if (!stop) return ;
	vec.push_back(ev);
	while (m[ev] != sv) {
		vec.push_back(m[ev]);
		ev = m[ev];
	}
	vec.push_back(sv);
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << "<-";
	}
}

vector<int> getPathDFSHelper(int **edges, int v, bool* visited, int sv, int ev, vector<int> vec) {
	if (sv == ev) {
		vec.push_back(sv);
		return vec;
	}
	visited[sv] = true;
	for (int i = 0; i < v; i++) {
		if (!visited[i] && edges[sv][i]) {
			// visited[i] = true;
			vector<int> s = getPathDFSHelper(edges, v, visited, i, ev, vec);
			if (s.size() >= 1) {
				s.push_back(sv);
				return s;
			}
		}
	}
	return vec;
}
void getPathDFS(int **edges, int v, int sv, int ev) {
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}
	vector<int> vec;
	vec = getPathDFSHelper(edges, v, visited, sv, ev, vec);
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << "<-";
	}
}
int main() {
	int v, e;
	cin >> v >> e;
	int **edges = new int*[v];
	for (int i = 0; i < v; i++) {
		edges[i] = new int[v];
		for (int j = 0; j < v; j++) {
			edges[i][j] = 0;
		}
	}
	int f, s;
	for (int i = 0; i < e; i++) {
		cin >> f >> s;
		edges[f][s] = edges[s][f] = 1;
	}
	int sv, ev;
	cin >> sv >> ev;
	cout << endl << "BFS: ";
	getPathBFS(edges, v, sv, ev);
	cout << endl << "DFS: ";
	getPathDFS(edges, v, sv, ev);
	for (int i = 0; i < v; i++) {
		delete[] edges[i];
	}
	delete[] edges;
}