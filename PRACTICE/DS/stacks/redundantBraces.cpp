#include<iostream>
using namespace std;
int braces(string A) {
	stack<char> s;
	for (auto c : A) {
		if (c == ')') {
			char t = s.top(); s.pop();
			int flag = 1;
			while (t != '(') {
				if (t == '+' || t == '-' || t == '*' || t == '/')
					flag = 0;
				t = s.top(); s.pop();
			}
			if (flag)
				return 1;
		} else {
			s.push(c);
		}
	}
	return 0;
}
int main()
{

}