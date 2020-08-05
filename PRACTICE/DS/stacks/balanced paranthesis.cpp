#include<iostream>
#include<stack>
using namespace std;
bool ArePair(char opening, char closing) {
  if (opening == '(' && closing == ')') return true;
  else if (opening == '{' && closing == '}') return true;
  else if (opening == '[' && closing == ']') return true;
  return false;
}
bool AreParanthesesBalanced(string exp)
{
  stack<char> s;
  for (int i = 0; i < exp.length(); i++)
  {
    if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
      s.push(exp[i]);
    else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
    {
      if (s.empty() || !ArePair(s.top(), exp[i]))
        return false;
      else
        s.pop();
    }
  }
  return s.empty() ? true : false;
}
int main()
{
  string expression;
  cout << "Enter an expression:  ";
  cin >> expression;
  if (AreParanthesesBalanced(expression))
    cout << "Balanced\n";
  else
    cout << "Not Balanced\n";
}