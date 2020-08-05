#include <iostream>
using namespace std;

int power(int x,int p){
	if (p==0){return 1;}
	return x*power(x,(p-1));
}


int main(){
	int x,p;
	cin>>x>>p;
	cout<<power(x,p);
}