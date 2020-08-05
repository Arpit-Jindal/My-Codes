#include <iostream>
using namespace std;
int* primeArray = new int[10000]();
class queue {
	int n, frontidx, rear;
	int* arr;
public:
	queue() {
		n = 10000;
		arr = new int[n];
		frontidx = 0;
		rear = 0;
	}
	void push(int d) {
		arr[rear++] = d;
	}
	bool empty() {
		if (frontidx == rear) return true;
		return false;
	}
	int front() {
		return arr[frontidx];
	}
	void pop() {
		frontidx++;
	}
};
void sieve() {
	int n = 9999;
	bool* prime = new bool[n + 1]();
	prime[2] = true;
	for (int i = 3; i < n; i += 2) {
		prime[i] = true;
	}
	for (int i = 3; i * i <= n; i += 2) {
		if (prime[i]) {
			for (int j = i * i; j <= n; j += 2 * i) {
				prime[j] = false;
			}
		}
	}
	int j = 0;
	for (int i = 1000; i <= n; i++) {
		if (prime[i]) {
			primeArray[j++] = i;
		}
	}
}
class node {
public:
	int data;
	node* next;
	node() {
		next = NULL;
	}
	node(int d) {
		data = d;
		next = NULL;
	}
};
class list {
public:
	node* head;
	void push_front(int d) {
		node* new_node = new node(d);
		new_node->next = head;
		head = new_node;
	}
};
class Graph {
public:
	int V;
	list* adjList;

	Graph(int v) {
		V = v;
		adjList = new list[V];
		for (int i = 0; i < V; i++) {
			adjList[i].head = NULL;
		}
	}
	void addEdge(int v1, int v2) {
		adjList[v1].push_front(v2);
		adjList[v2].push_front(v1);
	}
	int shortest_path(int v1, int v2) {
		int visited[V] = {0};
		queue q;
		visited[v1] = 1;
		q.push(v1);

		while (!q.empty()) {
			int curr = q.front(); q.pop();
			node* temp = adjList[curr].head;
			while (temp) {
				int val = temp->data;
				if (!visited[val]) {
					q.push(val);
					visited[val] = visited[curr] + 1;
				}
				if (val == v2) {
					return visited[val] - 1;
				}
				temp = temp->next;
			}
		}
	}
};
bool compare(int a, int b) {
	int c = 0;
	while (a > 0 && b > 0) {
		if ((a % 10) != (b % 10)) c++;
		a = a / 10;
		b = b / 10;
	}
	if (c == 1) return true;
	return false;
}
int main() {
	sieve();
	int n = 0;
	for (; n < 10000; n++) {
		if (primeArray[n] == 0)break;
	}
	//n = the no. of primes between 1000&9999
	Graph graph(n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (compare(primeArray[i], primeArray[j])) {
				graph.addEdge(i, j);
			}
		}
	}
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		int a, b; cin >> a >> b;
		int i1, i2;
		for (int i = 0; i < n; i++) {
			if (primeArray[i] == a) {
				i1 = i;
			}
			if (primeArray[i] == b) {
				i2 = i;
			}
		}
		int ans = graph.shortest_path(i1, i2);
		cout << "#" << i << " " << ans << "\n";
	}
	return 0;
}
