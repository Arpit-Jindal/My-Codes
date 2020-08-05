#include<iostream>
#include<queue> //priority_queue
#include<vector> //min priority_queue syntax
#include<functional> //greater<int> 
using namespace std;
int main()
{
	// priority_queue<int> pq; 	//By default pq is a max heap
	priority_queue<int, vector<int>, greater<int>>pq; //min Heap
	int a[10] = {15, 6, 17, 18, 9, 19};

	for (int i = 0; i < 6; i++) {
		pq.push(a[i]);
	}
	while (!pq.empty()) {
		cout << pq.top() << ",";
		pq.pop();
	}

}