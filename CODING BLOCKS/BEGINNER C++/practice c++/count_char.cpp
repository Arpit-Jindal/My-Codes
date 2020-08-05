#include<iostream>
using namespace std;

int main() {
	char a;
	a=cin.get(); /*cin ignores the white spaces..get() doesn't
					white spaces = enter,tab,space */
	int i=0;
	while (a!='$'){
		a=cin.get();
		i++;
	}
	cout<<i;
}