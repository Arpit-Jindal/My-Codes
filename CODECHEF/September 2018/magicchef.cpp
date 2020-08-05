#include<iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int n, x, s;
        cin >> n >> x >> s;
        int a, b;
        int output = x;
        for (int j = 1; j <= s; j++)
        {
            cin >> a >> b;
            if (a == output) output = b;
            else if (b == output) output = a;
        }
        cout << output << endl;
    }

}
