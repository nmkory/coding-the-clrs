// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
#include <iostream>

using namespace std;

void printCutRodSolution(const int32_t* revenue_table,
                         const int32_t* size_table, int32_t n)
{
  //print out the revenue of our size
  cout << revenue_table[n] << '\n';

  //for our value, print out the optimal rod sizes and reduce by n
  while (n > 0)
  {
    cout << size_table[n] << ' ';
    n = n - size_table[n];
  }

  //print out sentinel value to note end
  cout << "-1" << '\n';
}  //printCutRodSolution()


void extendedBottomUpCutRod(int32_t* price_table, int32_t* revenue_table,
                            int32_t* size_table, const int32_t length)
{
  int32_t i;
  int32_t j;
  int32_t q;  //temp max revenue

  //set revenue for length of 0
  revenue_table[0] = 0;

  //for length of rod, determine the first cut and revenue
  for (j = 1; j <= length; j++)
  {
    //set or reset q to sentinel value
    q = INT32_MIN;

    //for each piece up to current length
    for (i = 1; i <= j; i++)
    {
      //set q based on stored values in revenue table and update size table
      if (q < price_table[i] + revenue_table[j - i])
      {
        q = price_table[i] + revenue_table[j - i];
        size_table[j] = i;
      }  //if entered, stored values were updated
    }  //after for loop, all the values for up to this length are updated

    //update the revenue table with the new max revenue
    revenue_table[j] = q;
  } //after for loop, optimal revenue and sizes are stored in their tables
}  //extendedBottomUpCutRod()


int main(int argc, char* argv[])
{
  int32_t length;
  int32_t i;
  int32_t* price_table;
  int32_t* revenue_table;
  int32_t* size_table;

  //first cin is the length of the arrays
  cin >> length;
  price_table = new int32_t [length + 1];
  revenue_table = new int32_t [length + 1];
  size_table = new int32_t [length + 1];

  //load the unsorted array from input
  for (i = 1; i <= length; i++)
    cin >> price_table[i];

  extendedBottomUpCutRod(price_table, revenue_table, size_table, length);

  printCutRodSolution(revenue_table, size_table, length);

  //free allocated space
  delete[] price_table;
  delete[] revenue_table;
  delete[] size_table;

  return 0;
}  //main()
