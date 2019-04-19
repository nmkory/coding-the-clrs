// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
// I did not work with anyone on this assignment.
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Node {
  public:
    Node* parent {NULL};
    Node* left {NULL};
    Node* right {NULL};
    int key {0};

    Node() {}
    Node(Node* parent, Node* leftNode, Node* rightNode, int key)
      : parent(parent), left (leftNode), right (rightNode), key (key) {}
    ~Node() {}


    //clean tree used to free leaked memory from Node allocations
    void cleanTree()
    {
      if (left)
      {
        left->cleanTree();
        delete left;
      } //if node left

      if (right)
      {
        right->cleanTree();
        delete right;
      } //if node right
    } //cleanTree()
};  //class Node


class BST {
  public:
    Node* root {NULL};

    BST() {}
    BST(Node* root) : root (root) {}
    ~BST() {
      root->cleanTree();
      delete root;
    }


    void transplant(Node* u, Node* v)
    {
      if (u->parent == NULL)
        root = v;
      else if (u == u->parent->left)
        u->parent->left = v;
      else
        u->parent->right = v;

      if (v != NULL)
        v->parent = u->parent;
    }  //transplant()


    void treeInsert(Node* z)
    {
      Node* y = NULL;
      Node* x = root;

      while (x != NULL)
      {
        y = x;
        if (z->key < x->key)
          x = x->left;

        else
          x = x->right;
      }

      z->parent = y;

      if (y == NULL)
        root = z; //tree was empty

      else if (z->key < y->key)
        y->left = z;

      else
        y->right = z;
    }  //treeInsert()
};  //class BST


int main(int argc, char* argv[])
{
  char command;
  int key;
  string walk;
  bool incoming_input = true;
  Node* z;
  BST* tree = new BST();

  //while there is still input commands
  while (incoming_input) {
    cin >> command;
    switch (command) {
      case 'i':
        cin >> key;
        z = new Node (NULL, NULL, NULL, key);
        tree->treeInsert(z);
        break;
      case 'd':
        break;
      case 'o':
        cin >> walk;
        if (walk == "pre")
          break;
        else if (walk == "post")
          break;
        else
          break;
      case 'e' :
        incoming_input = false;
        break;
      default :
        incoming_input = false;
    }  //end of switch
  }  //after while loop, we have finished with input

  //free allocated space
  delete tree;

  return 0;
}  //main()
