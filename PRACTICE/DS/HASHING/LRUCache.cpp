#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>

int cap;
unordered_map<int, int> m; //key->value mapping
unordered_map<int, list<int>::iterator> map_list; //key->list_address mapping
list<int> linked_list; //storing all the keys

LRUCache::LRUCache(int capacity) {
	cap = capacity;
	m.clear(); map_list.clear(); linked_list.clear();
}

int LRUCache::get(int key) {
	if (m.find(key) == m.end())return -1;
	set(key, m[key]);
	return m[key];
}

void LRUCache::set(int key, int value) {
	if (m.find(key) == m.end()) {
		if (m.size() == cap) {
			int k = linked_list.back();
			linked_list.pop_back();
			map_list.erase(k);
			m.erase(k);
		}
	}
	else linked_list.erase(map_list[key]);

	linked_list.push_front(key);
	map_list[key] = linked_list.begin();
	m[key] = value;
}

class LRUCache {
public:
	list<pair<int, int>> dq;
	map<int, list<pair<int, int>>::iterator> m;
	int cp;
	LRUCache(int);
	int get(int);
	void set(int, int);
};
LRUCache::LRUCache(int capacity) {
	dq.clear();
	m.clear();
	cp = capacity;
}
int LRUCache::get(int key) {
	auto it = m.find(key);
	if (it != m.end()) {
		int val = (it->second)->second;
		set(key, val);
		return val;
	}
	return -1;
}
void LRUCache::set(int key, int value) {
	if (m.find(key) == m.end()) {
		if (dq.size() == cp) {
			pair<int, int> p = dq.back();
			dq.pop_back();
			m.erase(p.first);
		}
	}
	else {
		dq.erase(m[key]);
	}
	dq.push_front(make_pair(key, value));
	m[key] = dq.begin();
}

int main()
{

}