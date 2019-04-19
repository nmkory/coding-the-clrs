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


    //overloaded== operator
    bool operator== (const Node* rhs) const
    {
      return key == rhs->key;
    }  //operator==


    //overloaded!= operator
    bool operator!= (const Node* rhs) const
    {
      return key != rhs->key;
    }  //operator!=


    //clean tree used to free leaked memory from Node allocations
    void cleanTree()
    {
      if (left != NULL)
      {
        left->cleanTree();
        delete left;
      } //if node left

      if (right != NULL)
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
      if (root)
      {
      root->cleanTree();
      delete root;
      }
    }


    Node* treeMinimum(Node* x)
    {
      while (x->left != NULL)
        x = x->left;
      return x;
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

      //delete u;
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


    void treeDelete(Node* z)
    {
      Node* y;

      if (z->left == NULL)
        transplant(z, z->right);
      else if (z->right == NULL)
        transplant(z, z->left);
      else
      {
        y = treeMinimum(z->right);
        if (y->parent != z)
        {
          transplant(y, y->right);
          y->right = z->right;
          y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
      }
    }


    void preorderTreeWalk (Node* x)
    {
      if (x != NULL)
      {
        std::cout << x->key << '\n';
        preorderTreeWalk (x->left);
        preorderTreeWalk (x->right);
      }
    }


    void postorderTreeWalk (Node* x)
    {
      if (x != NULL)
      {
        postorderTreeWalk (x->left);
        postorderTreeWalk (x->right);
        std::cout << x->key << '\n';
      }
    }


    void inorderTreeWalk (Node* x)
    {
      if (x != NULL)
      {
        inorderTreeWalk (x->left);
        std::cout << x->key << '\n';
        inorderTreeWalk (x->right);
      }
    }
};  //class BST


int main(int argc, char* argv[])
{
  char command;
  int key;
  string walk;
  string pre = "pre";
  string post = "post";
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
        cin >> key;
        z = new Node (NULL, NULL, NULL, key);
        tree->treeDelete(z);
        break;
      case 'o':
        cin >> walk;
        //std::cout << walk << '\n';
        if (walk.compare(pre) == 0)
        {
          tree->preorderTreeWalk(tree->root);
          walk.clear();
          break;
        }
        else if (walk.compare(post) == 0)
        {
          tree->postorderTreeWalk(tree->root);
          walk.clear();
          break;
        }
        else
        {
          tree->inorderTreeWalk(tree->root);
          walk.clear();
          break;
        }
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