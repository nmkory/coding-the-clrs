// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
#include <iostream>
#include <cstring>

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


void countingSort(int** array, int** temp_array, int radix_digit, int length)
{
  int i;
  int j;
  int count_array[10];

  memset(count_array, -1, sizeof(count_array));

  for (j = 0; j < length; j++)
    count_array[array[j][radix_digit]]++;

  for (i = 1; i < 10; i++)
    count_array[i] = count_array[i] + count_array[i-1];

  for (j = length - 1; j >= 0; j--)
  {
    temp_array[count_array[array[j][radix_digit]]] = array[j];
    count_array[array[j][radix_digit]]--;
  }

  printArray(temp_array, length);

  // for (j = 0; j < length; j++)
  //   array[j] = temp_array[j];

}  //countingSort()


int main(int argc, char* argv[])
{
  int length;
  int key;
  int radix_digit;
  int count = 0;
  int** array;
  int** temp_array;

  //first cin is the length of the array to be sorted and load the 2D array
  cin >> length;
  array = new int* [length];
  loadArray(array, length);

  temp_array = new int* [length];

  //radix sort
  //for(radix_digit = 9; radix_digit >=0; radix_digit--)
    countingSort(array, temp_array, 9, length);

  printArray(array, length);

  //free allocated space
  for (int j = 0; j < length; j++)
    delete[] array[j];
  delete[] array;
  delete[] temp_array;

  return 0;
}  //main()
