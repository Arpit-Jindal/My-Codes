#include <iostream>

using namespace std;

int main() {
    int lines;
    cin >> lines;

    for (int currow = 1; currow <= lines; ++currow)
    {
        for (int val = 1; val <= currow; val++) {
            cout << val << " ";

        }
        cout << endl;
    }


}

