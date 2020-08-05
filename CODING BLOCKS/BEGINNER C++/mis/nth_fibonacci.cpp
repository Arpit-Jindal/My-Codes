#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int f=0,s=1,j=2;

	if (n==1){cout<<f;}
	else if (n==2){cout<<s;}
	else if(n>2){
		for(int i=1;i<=n;i++)
		{
		int next = f + s;
		f=s;
		s=next;
		j++;
		if (j==n){cout<<next;
			return 0;}
		}
	}
}