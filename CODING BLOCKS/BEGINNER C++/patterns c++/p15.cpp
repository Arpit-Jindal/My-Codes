#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n-i;j++)
        {
            cout<<" ";
        }
        for (int k=n-1;k<2*n-1;k++)
        {
            
            if(i==1 or i==n){cout<<"*";}
            else {cout<<"*";
            for (int x=1;x<=n-2;x++){
                cout<<" ";
            }
            cout<<"*";
            break;
            }
        }
        cout<<endl;
    }
    return 0;
}