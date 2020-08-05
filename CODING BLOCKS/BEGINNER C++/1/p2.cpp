#include <iostream>
using namespace std;
int main()
{	
	int lines;
	cin>>lines;
	for (int currow=1;currow<=lines;currow++)
	{

		for (int space= 1;space<=lines - currow;space++)
			{
				cout<<" ";
			}
		for (int value =1;value<=2*currow - 1;value++)
		{	
			cout  << value;

			}

			
		
		cout<<endl;
	}

}