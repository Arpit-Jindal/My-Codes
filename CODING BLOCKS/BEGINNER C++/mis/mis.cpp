#include <iostream>
using namespace std;
int odd(int n){
	for(int i=1;i<=n;i+=2)
	{
		cout<<i<<endl;

	}
}
int main(){
	int p;
	cin>>p;
	cout<<odd(p)<<endl;
}
