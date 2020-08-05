#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j =1;j<=i;j++)
        {
            if (i<=2){cout<<i<<"\t";}
            else{
                int x=0;
                cout<<i<<"\t";
                for (int k=1;k<=i-2;k++){
                    cout<<x<<"\t";
                }
                cout<<i<<"\t";
                break ;
            }
        }
        cout<<endl;
    }
}
