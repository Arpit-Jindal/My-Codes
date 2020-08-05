#include <iostream>
#include <stack>
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
string preToPost(string exp)
{
  stack<string> s;
  for (int i = exp.size() - 1; i >= 0; i--) 
  {
    if (isOperator(exp[i]))
    {
      string op1 = s.top(); s.pop();
      string op2 = s.top(); s.pop();
      string temp = op1 + op2 + exp[i];
      s.push(temp);
    }
    else
      s.push(string(1, exp[i]));
  }
  return s.top();
}
int main()
{
  string exp;
  cin >> exp;
  cout << "Postfix : " << preToPost(exp);
}