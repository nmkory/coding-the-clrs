// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
#include <iostream>
#include <list>

using namespace std;

int hashFunction (int k, int m)
{
  //return k modded by m
  return (k % m);
}  //hashFunction ()


void insertKey(list<int>** hash_table, int m, int key)
{
  //hash the key and place it at the front of the appropriate list
  hash_table[hashFunction(key, m)]->emplace_front(key);
}  //insertKey()


void searchKey(list<int>** const hash_table, int m, int key)
{
  int i = hashFunction(key, m);
  int j = 0;
  list<int>::iterator it;

  cout << key << ":";

  //for every key in the row
  for (it = hash_table[i]->begin(); it != hash_table[i]->end(); it++, j++) {
    //if we find our key
    if (key == *it)
    {
      cout << "FOUND_AT" << i << "," << j << ";" << '\n';
      return;
    } //we have found the key
  }  //if we reach end of for loop, the key was not found

  //cout that key was not found
  cout << "NOT_FOUND;" << '\n';
}  //deleteKey()


void deleteKey(list<int>** hash_table, int m, int key)
{
  int i = hashFunction(key, m);
  list<int>::iterator it;

  cout << key << ":";

  //for every key in the row
  for (it = hash_table[i]->begin(); it != hash_table[i]->end(); it++) {
    //if we find our key
    if (key == *it)
    {
      //remove it from the hash table's row
      hash_table[i]->erase(it);
      cout << "DELETED;" << '\n';
      return;
    }  //we found the key we wanted to delete
  }  //if we reach end of for loop, the key was not found

  //cout that key was not deleted
  cout << "DELETE_FAILED;" << '\n';
}  //deleteKey()


void output(list<int>** const hash_table, int m)
{
  int i;
  list<int>::iterator it;

  //for every row in the hash table
  for (i = 0; i < m; i++) {
    cout << i << ":";

    //for every key value
    for (it = hash_table[i]->begin(); it != hash_table[i]->end(); it++)
      cout << *it << "->";

    cout << ";" << '\n';
  } //all rows and their keys are outputted
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

  //while there is still input commands
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
    }  //end of switch
  }  //after while loop, we have finished with this hash table

  //free allocated space
  for (int j = 0; j < m; j++)
    delete hash_table[j];
  delete[] hash_table;

   return 0;
}  //main()
