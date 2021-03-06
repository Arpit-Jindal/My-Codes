#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
bool isoperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/')
        return true;
    return false;
}
bool IsNumericDigit(char C)
{
    if (C >= '0' && C <= '9')
        return true;
    return false;
}
int PerformOperation(char operation, int operand1, int operand2)
{
    if (operation == '+') return operand1 + operand2;
    else if (operation == '-') return operand1 - operand2;
    else if (operation == '*') return operand1 * operand2;
    else if (operation == '/') return operand1 / operand2;

    else {
        cout << "Unexpected Error \n";
        return -1;
    }
}
int EvaluatePostfix(string expression)
{
    stack<int> s;
    for (int i = 0; i < expression.length(); i++)
    {
        // if (expression[i] == ' ' || expression[i] == ',') continue;
        if (IsNumericDigit(expression[i]))
        {
            s.push(expression[i] - '0');
            // int operand = 0;
            // while (i < expression.length() && IsNumericDigit(expression[i]))
            // {
            //     operand = (operand * 10) + (expression[i] - '0');
            //     i++;
            // }
            // i--;
        }
        else if (isoperator(expression[i]))
        {
            if (s.empty()) 
                return -1;
            int op2 = s.top(); s.pop();
            if (s.empty()) 
                return -1;
            int op1 = s.top(); s.pop();
            int result = PerformOperation(expression[i], op1, op2);
            s.push(result);
        }
    }
    if (s.empty()) 
        return -1;
    int ans = s.top(); s.pop();
    if (!s.empty()) 
        return -1;
    return ans;
}
int main()
{
    string exp;
    cout << "Enter Postfix Expression: ";
    getline(cin, exp);
    int result = EvaluatePostfix(exp);
    if (result == -1)
        cout << "INVALID EXPRESSION";
    else
        cout << "output: " << result << endl;
}