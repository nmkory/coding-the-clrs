// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
#include <iostream>

using namespace std;

void printArray(const int32_t* array, int length)
{
  //print out the status of the array
  for (int i = 0; i < length; i++)
    cout << array[i] << ";";
}  //printArray()


void merge(int32_t* array, int p, int q, int r)
{
  int i;
  int j;
  int n1 = q - p + 1;  //size of rhs subarray
  int n2 = r - q;  ///size of lhs subarray
  int32_t* lhs = new int32_t [n1 + 1];  //add one for max value in last ele
  int32_t* rhs = new int32_t [n2 + 1];  //add one for max value in last ele

  //adjusted for array starting at 0, copy main array into temp subarray
  for (i = 0; i < n1; i++)
    lhs[i] = array[p + i];

  //adjusted for array starting at 0, copy main array into temp subarray
  for (j = 0; j < n2; j++)
    rhs[j] = array[q + j + 1];

  //last element of subarray should have infinite value so loops below work
  lhs[n1] = INT32_MAX;
  rhs[n2] = INT32_MAX;

  //reset indicies
  i = 0;
  j = 0;

  //for each element of left most pos of this subarray to right most pos
  for (int k = p; k <= r; k++)
  {
    //if the lhs sub element is less than or equal to right, sort it into main
    if (lhs[i] <= rhs[j])
    {
      array[k] = lhs[i];
      i++;
    }  //lhs is sorted into main sub

    //else rhs sub element is less than left, sort it into main
    else
    {
      array[k] = rhs[j];
      j++;
    }  //rhs is sorted into main sub
  }  //end of for loop means subarrays are sorted back into main array

  //free allocated space
  delete[] lhs;
  delete[] rhs;
}  //merge()


void mergeSort(int32_t* array, int p, int r)
{
  //if there is more than one element in each subarray
  if (p < r)
  {
    int q = ((p + r) / 2);
    mergeSort(array, p, q);
    mergeSort(array, q + 1, r);
    merge(array, p, q, r);
  }  //else we have reached base case (1 ele in subarray) so do nothing
}  //mergeSort()


int main(int argc, char* argv[])
{
  int length;
  int32_t* array;

  //first cin is the length of the array to be sorted
  cin >> length;
  array = new int32_t [length];

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
