// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
#include <iostream>

using namespace std;

void loadArray(int** array, int length)
{
  int j;
  int k;
  int temp;

  for (j = 0; j < length; j++)
  {
    array[j] = new int [10];

    for (k = 0; k < 10; k++)
      cin >> array[j][k];
  }
}  //loadArray()


void printArray(int** array, int length)
{
  int j;
  int k;

  for (j = 0; j < length; j++)
  {
    for (k = 0; k < 10; k++)
      cout << array[j][k] << ";";

    cout << endl;
  }
}  //printArray()


int main(int argc, char* argv[])
{
  int length;
  int key;
  int i;
  int count = 0;
  int** array;

  //first cin is the length of the array to be sorted and load the 2D array
  cin >> length;
  array = new int* [length];
  loadArray(array, length);

  printArray(array, length);

  //free allocated space
  for (int j = 0; j < length; j++)
    delete[] array[j];
  delete[] array;

  return 0;
}  //main()
