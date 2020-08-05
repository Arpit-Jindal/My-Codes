#include <iostream>
using namespace std;
int main() {


	int N;
	cin >> N;


	for (int curnum = 2; curnum <= N; curnum++)
	{
		int flag = 0;
		for (int div = 2; div < curnum; div++)
		{
			if (curnum % div == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0) {cout << curnum << " ";}
	}

}