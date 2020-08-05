#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x = 280;
	char*p = (char*)&x;
	printf("%d\n", *p);
	return 0;
}