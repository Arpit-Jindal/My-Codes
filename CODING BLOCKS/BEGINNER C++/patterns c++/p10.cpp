#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (i <= 3 or i % 2 == 1) {cout << "1";}
            else if (i % 2 == 0) {
                int x = 0;
                cout << "1";
                for (int k = 1; k <= i - 2; k++){cout << x;}
                cout << "1";
                break;
            }
        }
        cout << endl;
    }
}