#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    for (int i=1;i<=n/2 + 1;i++){
        for (int space=1;space<=n/2 + 1 -i;space++){
            cout<<"\t";
        }
        for (int j=1;j<=2*i-1;j++){
            cout<<"*\t"; 
        }
        cout<<endl;
    }
            int no=1; int x=n-2;
    for (int i=1;i<=n/2;i++)
    {
        for (int space=1;space<=no;space++)
        {
            cout<<"\t";
        }
        no++; 
        for (int j=x;j>=1;j--){
            cout<<"*\t";
        }
        x=x-2;
        cout<<endl;
        
    }
        
    
}