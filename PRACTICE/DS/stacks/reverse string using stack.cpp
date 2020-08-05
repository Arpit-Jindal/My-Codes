#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
void Reverse(string e)
{
    stack<char> s;
    for (int i = 0; i < e.length(); i++)
        s.push(e[i]);
    for (int i = 0; i < e.length(); i++) {
        e[i] = s.top();
        s.pop();
    }
    cout << e;
}
int main()
{
    // char c[100];
    // cout<<"enter string: ";
    // gets(c);
    // Reverse(c,strlen(c));
    // printf("output: %s",c);

    string expression;
    cout << "Enter an expression:  ";
    cin >> expression;
    Reverse(expression);

}
