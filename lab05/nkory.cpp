// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
#include <iostream>
#include <vector>

using namespace std;

void loadArray(vector<int>* array, int length)
{
  int j;
  int k;
  int temp;

  for (j = 0; j < length; j++)
  {
    for (k = 0; k < 10; k++)
    {
      cin >> temp;
      array[j].push_back(temp);
    }
  }
}  //loadArray()


void printArray(vector<int>* array, int length)
{
  for (int j = 0; j < length; j++)
  {
    for (vector<int>::iterator it = array[j].begin(); it != array[j].end();
         ++it)
      cout << *it << ";";

    cout << endl;
  }
}  //printArray()


int main(int argc, char* argv[])
{
  int length;
  int key;
  int i;
  int count = 0;
  vector<int>* array;

  //first cin is the length of the array to be sorted
  cin >> length;
  array = new vector<int> [length];


  loadArray(array, length);


  // //for each additional element to be received
  // for (int j = 1; j < length; j++)
  // {
  //   //take in the next element
  //   cin >> key;
  //
  //   //set i to the right most part of the sorted array
  //   i = j - 1;
  //
  //   //while we have not reached the end of the array and our new ele is smaller
  //   while (i >= 0 && array[i] > key)
  //   {
  //     //move the element back one position and start while loop over
  //     array[i + 1] = array[i];
  //     i--;
  //   }  //end of while loop means we found location for new element
  //
  //   //insert the element
  //   array[i + 1] = key;
  //
  //   //increment the count and print out the status of the array
  //   count++;
  //   printArray(array, count);
  // }  //end of insertion sort, all elements have been read and printed

  printArray(array, length);

  //free allocated space
  delete[] array;

  return 0;
}  //main()
