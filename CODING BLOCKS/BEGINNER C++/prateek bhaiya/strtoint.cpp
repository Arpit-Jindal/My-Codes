#include <iostream>
using namespace std;

int strtoint(char a[],int n){
	//n=length of string
	if(n==0){
		return 0;
	}
	int lastchar=a[n-1]-'0';
	int chotaans=strtoint(a,n-1);
	return chotaans*10 + lastchar;

}

int main(){
	cout<<strtoint("12345",5);	
}