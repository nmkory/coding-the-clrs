// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
#include <iostream>

using namespace std;

void printArray(const int* array, int length)
{
  //print out the status of the array
  for (int i = 0; i < length; i++)
    cout << array[i] << ";";
}  //printArray()


int partition(int* array, int p, int r)
{
  int x = array[r];
  int i = p - 1;
  int temp;

  for (int j = p; j < r; j++)
  {
    if (array[j] <= x)
    {
      i++;
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }

  temp = array[i + 1];
  array[i + 1] = array[r];
  array[r] = temp;

  return (i + 1);
}  //partition()


void quicksort(int* array, int p, int r)
{
  if (p < r)
  {
    int q = partition(array, p, r);
    quicksort(array, p, q - 1);
    quicksort(array, q + 1, r);
  }
}  //quicksort()


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

  //sort the array
  quicksort(array, 0, length - 1);

  //print result
  printArray(array, length);

  //free allocated space
  delete[] array;

  return 0;
}  //main()
