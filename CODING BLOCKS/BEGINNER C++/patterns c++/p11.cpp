#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (i <= 2) {cout << "1";}
            else {
                int x = 0;
                cout << i - 1;
                for (int k = 1; k <= i - 2; k++) {cout << x;}
                cout << i - 1;
                break;
            }
        }
        cout << endl;
    }

}
