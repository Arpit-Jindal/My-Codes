#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isoperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/')
        return true;
    return false;
}
bool IsNumericDigit(char C)
{
    if (C >= '0' && C <= '9') return true;
    return false;
}
int PerformOperation(char operation, int operand1, int operand2)
{
    if (operation == '+') return operand1 + operand2;
    else if (operation == '-') return operand1 - operand2;
    else if (operation == '*') return operand1 * operand2;
    else if (operation == '/') return operand1 / operand2;
    else cout << "Unexpected Error \n";
    return -1;
}
int EvaluatePrefix(string expression)
{
    stack<int> s;
    for (int i = expression.length() - 1; i >= 0; i--)
    {

        // if (expression[i] == ' ' || expression[i] == ',') continue;
        if (IsNumericDigit(expression[i]))
        {
            s.push(expression[i] - '0');

            // int operand = 0;
            // int count = 1;
            // while (i >= 0 && IsNumericDigit(expression[i]))
            // {
            //     operand = operand + (expression[i] - '0') * count;
            //     count *= 10;
            //     i--;
            // }
            // i++;
        }
        else if (isoperator(expression[i]))
        {
            int op1 = s.top(); s.pop();
            int op2 = s.top(); s.pop();
            int result = PerformOperation(expression[i], op1, op2);
            s.push(result);
        }
    }
    return s.top();
}
int main()
{
    string exp;
    cout << "enter prefix expression \n";
    getline(cin, exp);
    int result = EvaluatePrefix(exp);
    cout << "output: " << result << endl;
}

