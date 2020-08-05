#include<iostream>
#include<queue>
using namespace std;

class stack
{
	queue <int> q1, q2;
	int currentsize;
public:
	stack()
	{
		currentsize = 0;
	}
	void push(int x)
	{
		q1.push(x);
		currentsize++;
	}
	int pop()
	{
		if (q1.empty()) 
			return -1;
		while (q1.size() != 1)
		{
			q2.push(q1.front());
			q1.pop();
		}
		int temp = q1.front();
		q1.pop();
		
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
		return temp;
	}
	int size()
	{
		return currentsize;
	}
};

int main()
{
	stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.pop();
}
