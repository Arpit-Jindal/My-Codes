#include <iostream>
using namespace std;
int main()
{

	int lines;
	cin>> lines;
	int ithv=1;
	for (int currow=1;currow<=lines;currow++)
	{
		for (int val=1;val<=currow;val++)
		{
			cout<<ithv<<" ";
			++ithv;
		}
			cout<<endl;	
	}
	
}