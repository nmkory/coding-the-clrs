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


void countingSort(int** array, int** temp_array, int radix_digit, int length)
{
  int i;  //for loop index variable
  int j;  //for loop index variable
  int count_array[10];  //new array to hold freq of input elements

  //initialize count array to 0s
  for (i = 0; i < 10; i++)
    count_array[i] = 0;

  //count freq of elements by index (eg index 0 holds how many 0s there are)
  for (j = 0; j < length; j++)
    count_array[array[j][radix_digit]]++;

  //adds input elements to calculate stable sorting index for sort
  for (i = 1; i < 10; i++)
    count_array[i] = count_array[i] + count_array[i-1];

  //start sort from right to left
  for (j = length - 1; j >= 0; j--)
  {
    //move into temp_array index the right most index of a value (offset by 1)
    temp_array[count_array[array[j][radix_digit]] - 1] = array[j];
    //decrement that index in the count array
    count_array[array[j][radix_digit]]--;
  }  //temp array is now properly sorted based on the radix_digit

  //reset the pointers in array so array now holds the correct sorted order
  for (i = 0; i < length; i++)
   array[i] = temp_array[i];
}  //countingSort()


int main(int argc, char* argv[])
{
  int length;
  int radix_digit;
  int** array;
  int** temp_array;

  //first cin is the length of the array to be sorted and load the 2D array
  cin >> length;
  array = new int* [length];  //array of pointers for loaded values
  loadArray(array, length);

  temp_array = new int* [length];  //array of pointers for counting sort

  //radix sort using countingSort
  for(radix_digit = 9; radix_digit >=0; radix_digit--)
    countingSort(array, temp_array, radix_digit, length);

  printArray(array, length);

  //free allocated space
  for (int j = 0; j < length; j++)
    delete[] array[j];
  delete[] array;
  delete[] temp_array;

  return 0;
}  //main()
