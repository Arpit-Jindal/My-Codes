#include<iostream>
using namespace std;

class twostacks
{
	int *arr;
	int top1, top2, size;
public:
	twostacks() {};
	twostacks(int x)
	{
		size = x;
		arr = new int [x];
		top1 = -1;
		top2 = size;
	}
	void push1(int x)
	{
		if (top1 < top2 - 1)
			arr[++top1] = x;
		else
			cout << "stack overflow\n";
	}
	void push2(int x)
	{
		if (top1 < top2 - 1)
			arr[--top2] = x;
		else
			cout << "stack overflow\n";
	}
	int pop1()
	{
		if (top1 == -1) 
			cout << "stack underflow\n";
		else
		{
			int x = arr[top1];
			top1--;
			return x;
		}
	}
	int pop2()
	{
		if (top2 == size) 
			cout << "stack underflow\n";
		else
		{
			int x = arr[top2];
			top2++;
			return x;
		}

	}
};

int main()
{
	twostacks s(5);
	s.push1(1);
	s.push2(5);
	s.push1(2);
	s.push2(4);
	s.push1(3);
	cout << "stack 1 :" << s.pop1() << endl;
	cout << "stack 2 :" << s.pop2();
}