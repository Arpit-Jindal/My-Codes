// https://ide.codingblocks.com/s/23137
#include<bits/stdc++.h>
using namespace std;
class Heap {
	vector<int> v;
	int parent(int i) {return (i - 1) / 2;}
	int left(int i) {return 2 * i + 1;}
	int right(int i) {return 2 * i + 2;}
	void heapify(int i) {
		//O(h)
		int l = left(i);
		int r = right(i);
		int largest = i;
		if (l < v.size() && v[l] > v[largest])
			largest = l;
		if (r < v.size() && v[r] > v[largest])
			largest  = r;
		if (largest != i) {
			swap(v[i], v[largest]);
			heapify(largest);
		}
	}
public:
	int top() {
		//O(1)
		if (empty()) return -1;
		return v[0];
	}
	bool empty() {
		return v.size() == 0;
	}
	void pop() {
		//O(h)
		if (empty()) return;
		swap(v[0], v[v.size() - 1]);
		v.pop_back();
		heapify(0);
	}
	void push(int d) {
		v.push_back(d);
		int i = v.size() - 1;
		while (i > 0 && v[parent(i)] < v[i]) {
			swap(v[parent(i)], v[i]);
			i = parent(i);
		}
	}
};
int main()
{
	Heap h;
	h.push(1); h.push(3); h.push(9); h.push(2); h.push(8);
	cout << h.top() << endl;
	h.pop();
	cout << h.top();
}