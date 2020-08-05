#include<iostream>
using namespace std;
void towerofhanoi(int n, char src, char helper, char dest)
{
	if (n > 0) {
		towerofhanoi(n - 1, src, dest, helper);
		cout << "Move " << n << " from " << src << " to " << dest << endl;
		towerofhanoi(n - 1, helper, src, dest);
	}
}
int main()
{
	towerofhanoi(3, 'A', 'B', 'C');
}