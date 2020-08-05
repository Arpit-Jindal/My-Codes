#include <iostream>
using namespace std;

int series(int n) //function declaration
{	
	//function definition
	int ans=0;
	for (int i = 1; i <= n; i++) {
		ans=ans+i;
	}
	cout<<ans;
}
int main(){
	int n;
	cin>>n;

	series(n);

}

