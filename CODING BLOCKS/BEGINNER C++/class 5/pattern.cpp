#include <iostream>
using namespace std;

void printstars(int n){
	for (int i=1;i<=n;i++){
		cout<<"*";
	}
	cout<<" ";
}

int main(){
	int n;
	cin>>n;
	int no=n+1;
	for (int i=1;i<=n;i++){
		printstars(i);
		printstars(no-i);
		printstars(no-i);
		printstars(i);

	cout<<endl;
}
}