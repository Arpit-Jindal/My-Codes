#include<iostream>
using namespace std;

int knapsack(int W, int wt[], int p[], int m[76][6], int n)
{
  if (n < 0 || W == 0)
    return 0;
  if (m[W][n] == -1)
  {
    if (W < wt[n])
      m[W][n] = knapsack(W, wt, p, m, n - 1);
    else
      m[W][n] = max(knapsack(W - wt[n], wt, p, m, n - 1) + p[n], knapsack(W, wt, p, m, n - 1));
  }
  return m[W][n];
}

int knapSack(int W, int wt[], int p[], int n)
{
  int i, w;
  int K[n + 1][W + 1];

  // Build table K[][] in bottom up manner
  for (i = 0; i <= n; i++)
  {
    for (w = 0; w <= W; w++)
    {
      if (i == 0 || w == 0)
        K[i][w] = 0;
      else if (wt[i - 1] <= w)
        K[i][w] = max(p[i - 1] + K[i - 1][w - wt[i - 1]],  K[i - 1][w]);
      else
        K[i][w] = K[i - 1][w];
    }
  }

  return K[n][W];
}

int main()
{
  int wt[] = {10, 20, 30};
  int p[] = {60, 5, 120};
  int W = 50;
  cout << knapSack(W, wt, p, 3);
}