#include<iostream>
#include<stack>
using namespace std;
class Queue
{
	stack <int> s1, s2;
	int currentsize;
public:
	void enQueue(int x)
	{
		s1.push(x);
		currentsize++;
	}
	int deQueue()
	{
		if (s1.empty() && s2.empty())
		{
			cout << "Q is empty";
			return 0;
		}
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		int x = s2.top();
		s2.pop();
		return x;
	}
	int size()
	{
		return currentsize;
	}
};

int main()
{
	Queue q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);

	cout << q.deQueue() << '\n';
	q.enQueue(4);
	cout << q.deQueue() << '\n';
	cout << q.deQueue() << '\n';
	cout << q.deQueue() << '\n';

}
