#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

// class stack1
// {
//     int capacity;
//     int Top;
//     char *arr;
// public:
//     stack1(int capacity)
//     {
//         this->capacity = capacity;
//         Top = -1;
//         arr = new char[capacity];
//     }
//     void push(char x)
//     {
//         arr[++Top] = x;
//     }
//     void pop()
//     {
//         Top--;
//     }
//     char top()
//     {
//         return arr[Top];
//     }
//     bool empty()
//     {
//         if (Top == -1)return true;
//         return false;
//     }

// };

bool isoperator(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
		return true;
	else
		return false;
}
bool isoperand(char c)
{
	if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		return true;
	else
		return false;
}
int prec(char c)
{
	if (c == '$')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
void InfixtoPostfix(string exp)
{
	stack<char> s;
	// int n = exp.length();
	// stack1 s(n);
	string postfix = "";
	for (int i = 0; i < exp.length(); i++)
	{
		if (isoperand(exp[i]))
			postfix += exp[i];
		else if (isoperator(exp[i]))
		{
			while ( !s.empty() && prec(s.top()) >= prec(exp[i]) && s.top() != '('  )
			{
				postfix += s.top();
				s.pop();
			}
			s.push(exp[i]);
		}
		else if (exp[i] == '(')
			s.push('(');
		else if (exp[i] == ')')
		{
			while (!s.empty() && s.top() != '(')
			{
				postfix += s.top();
				s.pop();
			}
			s.pop();
		}
	}
	while (!s.empty())
	{
		postfix += s.top();
		s.pop();
	}
	cout << "Postfix expression: " << postfix;
}
int main()
{
	string exp;
	cout << "Enter Infix expression: \n";
	getline(cin, exp);
	InfixtoPostfix(exp);
}