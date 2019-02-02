// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
#include <limits>
#include <iostream>

using namespace std;

void printArray(const int* array, int length)
{
  //print out the status of the array
  for (int i = 0; i < length; i++)
    cout << array[i] << ";";
}  //printArray()


void merge(int* array, int p, int q, int r)
{
  int i;
  int j;
  int n1 = q - p + 1;
  int n2 = r - q;
  int* lhs = new int [n1 + 1];
  int* rhs = new int [n2 + 1];

  //adjusted for array starting at 0
  for (i = 0; i < n1; i++)
    lhs[i] = array[p + i];

  //adjusted for array starting at 0
  for (j = 0; j < n2; j++)
    rhs[j] = array[q + j + 1];

  lhs[n1] = numeric_limits<int>::max();
  rhs[n2] = numeric_limits<int>::max();

  i = 0;
  j = 0;

  for (int k = p; k <= r; k++)
  {
    if (lhs[i] <= rhs[j])
    {
      array[k] = lhs[i];
      i++;
    }

    else
    {
      array[k] = rhs[j];
      j++;
    }
  }

  delete[] lhs;
  delete[] rhs;
}  //merge()


void mergeSort(int* array, int p, int r)
{
  if (p < r)
  {
    int q = ((p + r) / 2);
    mergeSort(array, p, q);
    mergeSort(array, q + 1, r);
    merge(array, p, q, r);
  }
}  //mergeSort()


int main(int argc, char* argv[])
{
  int length;
  int* array;

  //first cin is the length of the array to be sorted
  cin >> length;
  array = new int [length];

  //load the unsorted array from input
  for (int i = 0; i < length; i++)
    cin >> array[i];

  //start merge sorting
  mergeSort(array, 0, length - 1);

  //print result
  printArray(array, length);

  //free allocated space
  delete[] array;

  return 0;
}  //main()
