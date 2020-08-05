#include <iostream>
#include <cmath>
using namespace std;

int function(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int y = pow(-1, i) * i;
        ans = ans + y;
    }
    return ans;
}


int main() {
    int n;
    cin >> n;
    int aj[n];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        aj[i] = function(x);
    }
    for (int i = 0; i < n; i++) {
        cout << aj[i] << endl;
    }

}
