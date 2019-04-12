// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
#include <iostream>

using namespace std;

void printOptimalParens(int32_t** s, int32_t i, int32_t j)
{
  if (i == j)
  {
    std::cout << "A" << i;
  }

  else
  {
    std::cout << "(";
    printOptimalParens(s, i, s[i][j]);
    printOptimalParens(s, s[i][j] + 1, j);
    std::cout << ")";
  }
}  //printCutRodSolution()


int main(int argc, char* argv[])
{
  int32_t n;
  int32_t j;
  int32_t q;
  int32_t** m;
  int32_t** s;
  int32_t* p;


  //first cin is the amount of matrix and dimensions
  cin >> n;
  p = new int32_t [n + 1];
  for (int32_t i = 0; i <= n; i++)
    cin >> p[i];

  n--;

  m = new int32_t* [n + 1];
  for (int32_t i = 0; i <= n; i++)
  {
    m[i] = new int32_t [n + 1];
    for (int32_t r = 0; r <= n; r++)
      m[i][r] = 0;
  }

  s = new int32_t* [n];
  for (int32_t i = 0; i <= n-1; i++)
  {
    s[i] = new int32_t [n + 1];
    for (int32_t r = 0; r <= n; r++)
      s[i][r] = 0;
  }

  for (int32_t i = 1; i <= n; i++)
    m[i][i] = 0;

  for (int32_t l = 2; l <= n; l++)
  {
    for (int32_t i = 1; i <= (n - l + 1); i++)
    {
      j = i + l - 1;
      m[i][j] = INT32_MAX;
      for (int32_t k = i; k <= (j - 1); k++)
      {
        q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
        if (q < m[i][j])
        {
          m[i][j] = q;
          s[i][j] = k;
        }
      }
    }
  }

  std::cout << m[1][n] << '\n';

  printOptimalParens(s, 1, n);

  std::cout << "NO SEGFAULT" << '\n';

  return 0;
}  //main()
