#include <iostream>
using namespace std;
int main() {
    int n ;
    cin >>n;
    for (int i=0;i<n;i++)
    {
        int num=i;
        int dem=1;
        int no=1;
        for (int j=0;j<=i;j++)
        {
            cout<<no<<"\t";
            no=no*num/dem;
            num--;
            dem++;
        }
        cout<<endl;
    }
}
