#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    for (int i=1;i<=n/2 + 1;i++)
    {
        for (int j=1;j<=n/2 + 2 - i;j++) { cout<<"*\t";}       
        for (int k=2;k<=2*i - 2;k++){ cout<<"\t"; }
        if (i==1) {for (int k=1;k<=n/2;k++){cout<<"*\t"; }}
        else {for (int k=1;k<=n/2 + 2 -i;k++ ){cout<<"*\t";}}           
        cout<<endl;
    }   
            int x=0;
    for (int i=1;i<=n/2;i++)
    {
        for (int j=0;j<=i ;j++){cout<<"*\t";}
        for (int k=n-4-x;k>=1;k--){cout<<"\t"; 
        }
    	 x+=2;

        if (i==n/2){for (int k=1;k<=n/2;k++){cout<<"*\t"; }}
        else {for (int k=0;k<=i;k++){cout<<"*\t";}}
        cout<<endl;
        
        
    }
}
