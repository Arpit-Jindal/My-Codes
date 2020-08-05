#include<iostream>
#include<cstring>
using namespace std;
char* isPermutation(char* input1, char* input2)
{
	int count1[1000] = {0};
	int count2[1000] = {0};
	int i;
	for (i = 0; input1[i] && input2[i];  i++)
	{
		count1[input1[i]]++;
		count2[input2[i]]++;
	}
	if (input1[i] || input2[i])
	{
		return "no";
	}
	for (i = 0; i < 1000; i++)
	{
		if (count1[i] != count2[i])
		{
			return "no";
		}
	}

	return "yes";
}
int main()
{
	cout << isPermutation("arpit", "tpra");
}