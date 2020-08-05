#include<bits/stdc++.h>
using namespace std;
void print(priority_queue<int, vector<int>, greater<int>>pq) {
	while (!pq.empty()) {
		cout << pq.top() << ","; pq.pop();
	}
	cout << endl;
}
int main()
{
	int k = 3;
	priority_queue<int, vector<int>, greater<int>> pq;
	int cs = 0;//current size
	int no;
	while (scanf("%d", &no) != EOF) {
		if (no == -1) {
			print(pq);
		}
		else if (cs < k) {
			pq.push(no);
			cs++;
		}
		else {
			if (no > pq.top()) {
				pq.pop();
				pq.push(no);
			}
		}
	}
}