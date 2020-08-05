#include<iostream>
#include<cstring>
#include <vector>
using namespace std;
void SieveOfEratosthenes(int n)
{
	vector<bool> prime(n + 1, true);
	for (int p = 2; p * p <= n; p++)
	{
		if (prime[p] == true) {
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
}
// void sieveOfEratosthenes(int n)
// {
// 	vector<bool> prime(n + 1, false); // all unprime
// 	prime[2] = true;
// 	//Let us mark all odd nos as prime(Initialisations)
// 	for (int i = 3; i <= n; i += 2)
// 		prime[i] = true;

// 	//Sieve Logic to mark all unprime nos as 0
// 	//1. Optimisation:  Iterate only over odd nos
// 	for (int i = 3; i * i <= n; i += 2) {
// 		if (prime[i]) {
// 			//Mark all the multiples of that no. as non prime
// 			//2. Optimisation: Take a jump of 2i starting from i*i
// 			for (int j = i * i; j <= n; j += 2 * i)
// 				prime[j] = false;
// 		}
// 	}

// 	for (int p = 2; p <= n; p++)
// 	{
// 		if (prime[p])
// 			cout << p << " ";
// 	}
// }
int main() {
	sieveOfEratosthenes(100);
}