#include <iostream>
using namespace std;
int charcount(){
	char c;
	c=cin.get();
	int count=0;
	while (c!='$'){
		count ++;
	}
	cout<<count;
	return count;
}
int main(){
	charcount();

}