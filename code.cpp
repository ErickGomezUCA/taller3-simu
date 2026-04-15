#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int f(int i, int c, int A[], int n, int memo[1000][3])
{
  if (i == n)
    return 0;

  if (memo[i][c] != -1)
    return memo[i][c];

  int result;

  if (c == 2)
  {
    result = f(i + 1, 0, A, n, memo);
  }
  else
  {
    int no_take = f(i + 1, 0, A, n, memo);
    int take = A[i] + f(i + 1, c + 1, A, n, memo);
    result = max(no_take, take);
  }

  memo[i][c] = result;
  return result;
}

int main()
{
  int A[] = {4, 2, 7, 3, 6};
  int n = sizeof(A) / sizeof(A[0]);
  int memo[1000][3];

  for (int i = 0; i <= n; i++)
    for (int c = 0; c < 3; c++)
      memo[i][c] = -1;

  int result = f(0, 0, A, n, memo);

  cout << "Suma maxima: " << result << endl;

  return 0;
}