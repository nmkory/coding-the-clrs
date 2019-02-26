// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
#include <iostream>
#include <cstdlib>

using namespace std;

void printArray(const int* array, int length)
{
  //print out the status of the array
  for (int i = 0; i < length; i++)
    cout << array[i] << ";";
}  //printArray()


int partition(int* array, int p, int r)
{
  //pivot is set to rightmost element
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


int randomizedPartition(int* array, int p, int r)
{
  int i;  //random pivot index
  int temp;  //temp var for inplace swapping

  //choose a random i between and including p and r
  i = rand() % (r - p + 1) + p;

  //exchange array[r] with array[i] to set rand pivot
  temp = array[i];
  array[i] = array[r];
  array[r] = temp;

  //call partition with the rand pivot
  return partition(array, p, r);
}  //randomizedPartition()


void randomizedQuicksort(int* array, int p, int r)
{
  //if we are not at base case
  if (p < r)
  {
    int q = randomizedPartition(array, p, r);
    randomizedQuicksort(array, p, q - 1);
    randomizedQuicksort(array, q + 1, r);
  }
}  //randomizedQuicksort()


int main(int argc, char* argv[])
{
  int length;
  int* array;

  //seed rand with the current time
  srand(time(NULL));

  //first cin is the length of the array to be sorted
  cin >> length;
  array = new int [length];

  //load the unsorted array from input
  for (int i = 0; i < length; i++)
    cin >> array[i];

  //sort the array
  randomizedQuicksort(array, 0, length - 1);

  //print result
  printArray(array, length);

  //free allocated space
  delete[] array;

  return 0;
}  //main()
