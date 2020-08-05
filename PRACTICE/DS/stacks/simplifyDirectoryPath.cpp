#include<bits/stdc++.h>
using namespace std;
string simplifyPath(string A) {

    stack <string> s;

    for (int i = 0; i < A.length();)
    {

        if (A[i] == '/')
            i++;
        else if (A[i] == '.' && A[i + 1] == '.') {
            if (!s.empty()) s.pop();
            i += 2;
        }
        else if (A[i] == '.' && A[i + 1] != '.')
            i += 2;
        else {
            string t = "";
            while (A[i] && A[i] != '.' && A[i] != '/') {
                t += A[i];
                i++;
            }
            s.push(t);
        }

    }

    if (s.empty()) return "/";
    string ans = "";
    stack <string> st;

    while (!s.empty()) {
        st.push(s.top());
        s.pop();
    }

    while (!st.empty())
    {
        ans += '/' + st.top();
        st.pop();
    }
    return ans;
}
int main() {

}