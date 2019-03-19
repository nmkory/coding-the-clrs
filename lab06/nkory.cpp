// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
#include <iostream>
#include <list>

using namespace std;

void output(list<int>** const hash_table, int m)
{
  int i;
  list<int>::iterator it;

  for (i = 0; i < m; i++) {
    cout << i << ":";

    for (it = hash_table[i]->begin(); it != hash_table[i]->end(); it++)
      cout << *it << "->";

    cout << ";" << '\n';
  }
}  //output()


int hashFunction (int k, int m)
{
  return (k % m);
}  //hashFunction ()


int main(int argc, char* argv[])
{
  int m;
  char command;
  int value;
  list<int>** hash_table;
  bool incoming_input = true;

  //first cin is the length of the hash table and create table and linked lists
  cin >> m;
  hash_table = new list<int>* [m];
  for (int i = 0; i < m; i++)
    hash_table[i] = new list<int>;

  while (incoming_input) {
    cin >> command;
    switch (command) {
      case 'i':
        cin >> value;
        cout << "Insert " << value << '\n';
        hash_table[hashFunction(value, m)]->emplace_front(value);
        break;
      case 'd':
        cin >> value;
        cout << "Delete " << value << '\n';
        break;
      case 's':
        cin >> value;
        cout << "Search " << value << '\n';
        break;
      case 'o':
        cout << "Output all" << '\n';
        output(hash_table, m);
        break;
      case 'e' :
        incoming_input = false;
        break;
      default :
        incoming_input = false;
    }
  }

  //free allocated space
  for (int j = 0; j < m; j++)
    delete hash_table[j];
  delete[] hash_table;

   return 0;
}  //main()
