#include <iostream>

using namespace std;

void printArray(const int* array, const int count)
{
  for (int i = 0; i < count; i++) {
    cout << array[i] << ";";
  }
  cout << endl;
}

int main(int argc, char* argv[])
{
  int length;
  int key;
  int i;
  int count = 0;
  int* array;

  cin >> length;
  array = new int [length];

  cin >> array[0];
  count++;

  //for j = 2 to A.length
  for (int j = 1; j < length; j++)
  {
    //key = A[j]
    cin >> key;

    //i = j - 1
    i = j - 1;

    while (i >= 0 && array[i] > key)
    {
      array[i + 1] = array[i];
      i--;
    }

    array[i + 1] = key;

    count++;
    printArray(array, count);
  }

  //Free allocated space
  delete[] array;

  return 0;
}  //main()
