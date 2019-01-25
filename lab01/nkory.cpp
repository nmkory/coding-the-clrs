#include <iostream>
#include <fstream>

using namespace std;

void printArray(int* array, const int count, ofstream& result)
{
  for (int i = 0; i < count; i++) {
    result << array[i] << ";";
  }
  result << endl;
}

int main(int argc, char* argv[])
{
  char c;
  int length;
  int key;
  int i;
  int j;
  int count = 0;
  int* array;
  ifstream inf(argv[1]);
  ofstream result;

  result.open(argv[2]);

  inf >> c;
  length = c - '0';
  array = new int [length];

  inf >> c;
  array[0] = (c - '0');
  count++;

  //for j = 2 to A.length
  for (j = 1; j < length; j++)
  {
    //key = A[j]
    inf >> c;
    key = c - '0';

    //i = j - 1
    i = j - 1;

    while (i >= 0 && array[i] > key)
    {
      array[i + 1] = array[i];
      i--;
    }

    array[i + 1] = key;

    count++;
    printArray(array, count, result);
  }

  //Free allocated space
  delete[] array;

  result.close();

  return 0;
}  //main()
