#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int f=0;
	int s=1;
	if (n==0){cout<<f<<endl;}
	else {cout<<f<<endl<<s<<endl;
		for(int i=1;i<=n;i++)
		{
		int next = f + s;
		f=s;
		s=next;
		if(next>n){return 0;}
		cout<<next<<endl;

		}}
}