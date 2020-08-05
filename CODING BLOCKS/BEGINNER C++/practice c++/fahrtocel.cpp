#include<iostream>
using namespace std;

int ftoc(int n1, int n2, int step) {
    for (int i = n1; i <= n2; i += step)
    {
        double c = ((5.0) * (i - 32) / 9);
        cout << "\t" << i << "\t" << c << endl;
    }
}
int main() {
    int n1, n2, step;
    cin >> n1 >> n2 >> step;
    ftoc(n1, n2, step);

}