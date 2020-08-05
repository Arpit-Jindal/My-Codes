#include<bits/stdc++.h>
using namespace std;
void insertAtCorrectPos(stack<int> &s, int x) {
	if (s.empty() || s.top() > x) {
		s.push(x);
		return;
	}
	int y = s.top(); s.pop();
	insertAtCorrectPos(s, x);
	s.push(y);
}
void sortStack(stack<int> &s) {
	if (s.empty())return;
	int x = s.top(); s.pop();
	sortStack(s);
	insertAtCorrectPos(s, x);
}
void printstack(stack<int> s)
{
	while (!s.empty())
	{
		cout << s.top() << "->";
		s.pop();
	}
	cout << endl;
}
int main() {
	stack<int> s;
	s.push(5);
	s.push(8);
	s.push(1);
	s.push(7);
	s.push(2);
	printstack(s);
	sortStack(s);
	printstack(s);
}