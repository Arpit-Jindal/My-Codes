#include<iostream>
using namespace std;
int main()
{
    int** p, nr, nc, r, c;
    cin >> nr >> nc;
    p = new int *[nr];

    for (r = 0; r < nr; r++) {p[r] = new int [nc];}

    for (r = 0; r < nr; r++)
    {
        for (c = 0; c < nc; c++)
        {
            cin >> p[r][c];
        }
    }

    for (r = 0; r < nr; r++)
    {
        for (c = 0; c < nc; c++)
        {
            cout << p[r][c] << " ";
        }
        cout << endl;
    }
    delete p;
}