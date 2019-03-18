// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
#include <iostream>
#include <list>

using namespace std;

// void printArray(const int* array, int count)
// {
//   //print out the status of the array
//   for (int i = 0; i < count; i++)
//   {
//     cout << array[i] << ";";
//   }  //array has been printed
//
//   //print a new line per instructions
//   cout << endl;
// }  //printArray()


int main(int argc, char* argv[])
{
  bool incoming_input = true;
  int m;
  char command;
  int value;
  list<int>* hash_table;

  //first cin is the length of the hash table
  cin >> m;
  hash_table = new list<int> [m];

  while (incoming_input) {
    cin >> command;
    switch (command) {
      case 'i':
        cin >> value;
        std::cout << "Insert " << value << '\n';
        break;
      case 'd':
        cin >> value;
        std::cout << "Delete " << value << '\n';
        break;
      case 's':
        cin >> value;
        std::cout << "Search " << value << '\n';
        break;
      case 'o':
        std::cout << "Output all" << '\n';
        break;
      case 'e' :
        incoming_input = false;
      default :
        incoming_input = false;
    }
  }
   return 0;
}  //main()
