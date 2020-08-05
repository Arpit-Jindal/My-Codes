#include <iostream>
using namespace std;
int main() {
	int nlines;
	cin >> nlines;
	for (int currow = 1; currow <= nlines; currow++)
	{
		int nspaces = nlines - currow;
		for (int curspace = 1; curspace <= nspaces; curspace++)
		{
			cout << " ";

		}
		//print (2*curow - 1)  values
		int val = curow;
		int nval = 2 * curow - 1;
		bool is = false;
		for (int ithval = 1; ithval <= nval; ++ithval)
		{
			cout << val;
			if (val == nval) is = true;
			if (is = true) val--;
			else val++
			}
		cout << endl;
	}

}