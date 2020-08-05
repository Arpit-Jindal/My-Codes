#include <iostream>
using namespace std;

int xypath(int m,int n){

	if(m==1||n==1){return 1;}
	return xypath(m,n-1)+xypath(m-1,n);
}

int main(){
	int x,y;
	cin>>x>>y;
	cout<<xypath(x,y);
}