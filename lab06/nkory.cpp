// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
#include <iostream>
#include <list>

using namespace std;

int hashFunction (int k, int m)
{
  return (k % m);
}  //hashFunction ()


void insertKey(list<int>** hash_table, int m, int key)
{
  hash_table[hashFunction(key, m)]->emplace_front(key);
}  //insertKey()


void searchKey(list<int>** hash_table, int m, int key)
{
  int i = hashFunction(key, m);
  int j = 0;
  list<int>::iterator it;

  cout << key << ":";

  for (it = hash_table[i]->begin(); it != hash_table[i]->end(); it++, j++) {
    if (key == *it)
    {
      cout << "FOUND_AT" << i << "," << j << ";" << '\n';
      return;
    }
  }

  cout << "NOT_FOUND;" << '\n';
}  //deleteKey()


void deleteKey(list<int>** hash_table, int m, int key)
{
  int i = hashFunction(key, m);
  list<int>::iterator it;

  cout << key << ":";

  for (it = hash_table[i]->begin(); it != hash_table[i]->end(); it++) {
    if (key == *it)
    {
      hash_table[i]->erase(it);
      cout << "DELETED;" << '\n';
      return;
    }
  }

  cout << "DELETE_FAILED;" << '\n';
}  //deleteKey()


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


int main(int argc, char* argv[])
{
  int m;
  char command;
  int key;
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
        cin >> key;
        insertKey(hash_table, m, key);
        break;
      case 'd':
        cin >> key;
        deleteKey(hash_table, m, key);
        break;
      case 's':
        cin >> key;
        searchKey(hash_table, m, key);
        break;
      case 'o':
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
