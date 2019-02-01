// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
#include <iostream>

using namespace std;

void printArray(const int* array, int length)
{
  //print out the status of the array
  for (int i = 0; i < length; i++)
  {
    cout << array[i] << ";";
  }  //array has been printed

  //print a new line per instructions
  cout << endl;
}  //printArray()


void mergeSort(int* array, int p, int r)
{
  if (p < r)
  {
    int q = ((p + r)/2);
    mergeSort(array, p, q);
    mergeSort(array, q + 1, r);
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

  //print result
  printArray(array, length);

  //free allocated space
  delete[] array;

  return 0;
}  //main()
