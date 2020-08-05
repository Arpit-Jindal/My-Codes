#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int currow=1;currow<=n;currow++)
	{
		
		char val='A';
		for (int ithval=1;ithval<=currow;ithval++){
			cout<<val;
			val++;
		}	
		cout<<endl;		
	}
	
	}	
