#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	
	for (int currow=1;currow<=n;currow++)
	{
		/*int val=0;
		if (currow%2==1) val=0;
		else val=1;
		*/
		int val=(currow%2==1)?0:1;


		for (int ithval=1;ithval<=currow;ithval++){
			cout<<val;
			val=1-val;
		}
		cout<<endl;				
	}
	
	}	
