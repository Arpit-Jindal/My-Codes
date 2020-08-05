#include<iostream>
#include<stack>
using namespace std;
bool isOperator(char x) {
	switch (x) {
	case '+':
	case '-':
	case '/':
	case '*':
		return true;
	}
	return false;
}
string PostTopre(string exp)
{
	stack<string> s;
	for (int i = 0; i < exp.size(); i++)
	{
		if (isOperator(exp[i]))
		{
			string op2 = s.top(); s.pop();
			string op1 = s.top(); s.pop();
			string temp = exp[i] + op1 + op2;
			s.push(temp);
		}
		else
			s.push (string(1, exp[i]));
	}
	return s.top();
}
int main()
{
	string exp;
	cin >> exp;
	cout << "Postfix : " << PostTopre(exp);
}