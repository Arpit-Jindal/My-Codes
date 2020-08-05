#include<iostream>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
bool isoperator(char C) {
  if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$') return true;
  return false;
}
bool isoperand(char c) {
  if (c >= 'a' && c <= 'z') return true;
  else if (c >= 'A' && c <= 'Z') return false;
  else if (c >= '0' && c <= '9') return true;
  return false;
}
int prec(char c) {
  if (c == '^')
    return 3;
  else if (c == '*' || c == '/')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}
string InfixtoPostfix(string exp)
{
  stack<char> s;
  string postfix = "";

  for (int i = 0; i < exp.length(); i++)
  {
    if (isoperand(exp[i]))
    {
      postfix += exp[i];
    }
    else if (isoperator(exp[i]))
    {
      while ( !s.empty() && prec(exp[i]) <= prec(s.top()) && s.top() != '('  )
      {
        postfix += s.top();
        s.pop();
      }
      s.push(exp[i]);
    }
    else if (exp[i] == '(')
    {
      s.push('(');
    }
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
    char c = s.top();
    postfix += c;
    s.pop();
  }

  return postfix;
}

void InfixtoPrefix(string exp)
{
  reverse(exp.begin(), exp.end());
  for (int i = 0; i < exp.length(); i++)
  {
    if (exp[i] == '(') exp[i] = ')';
    else if (exp[i] == ')') exp[i] = '(';
  }
  string prefix = InfixtoPostfix(exp);
  reverse(prefix.begin(), prefix.end());
  cout << "Prefix: " << prefix;
}

int main()
{
  string exp;
  cout << "enter infix expression: \n";
  getline(cin, exp);
  InfixtoPrefix(exp);
}

