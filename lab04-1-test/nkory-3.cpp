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


int left(int i)
{
  //if root
  if (i == 0)
    return 1;

  else
    return ((2*i) + 1);
}  //left()


int right(int i)
{
  //if root
  if (i == 0)
    return 2;

  else
    return ((2*i) + 2);
}  //right()


void maxHeapify(int* array, int i, int heap_size)
{
  int largest;
  int temp;
  int l = left(i);
  int r = right(i);

  if ((l < heap_size) && (array[l] > array[i]))
    largest = l;

  else
    largest = i;

  if ((r < heap_size) && (array[r] > array[largest]))
    largest = r;

  if (largest != i)
  {
    temp = array[i];
    array[i] = array[largest];
    array[largest] = temp;
    maxHeapify(array, largest, heap_size);
  }
}  //maxHeapify()


void buildMaxHeap(int* array, int length, int heap_size)
{
  int i = (length / 2) - 1;

  if (i < 0)
    i = 0;

  for ( ; i >= 0; i--)
    maxHeapify(array, i, heap_size);
}  //buildMaxHeap()


int main(int argc, char* argv[])
{
  int length;
  int heap_size;
  int temp;
  int* array;

  //first cin is the length of the array to be sorted
  cin >> length;
  heap_size = length;
  array = new int [length];

  //load the unsorted array from input
  for (int i = 0; i < length; i++)
    cin >> array[i];

  //build the max heap
  buildMaxHeap(array, length, heap_size);

  //heapsort
  for (int i = length - 1; i > 0; i--)
  {
    temp = array[0];
    array[0] = array[i];
    array[i] = temp;
    maxHeapify(array, 0, --heap_size);
  }  //the maxheap has now been sorted

  //print result
  printArray(array, length);

  //free allocated space
  delete[] array;

  return 0;
}  //main()
