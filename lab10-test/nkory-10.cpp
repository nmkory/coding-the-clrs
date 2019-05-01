// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
// I did not work with anyone on this assignment.
//Test
#include <iostream>
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


    //overloaded== operator for node comparisons
    bool operator== (const Node* rhs) const
    {
      return key == rhs->key;
    }  //operator==


    //overloaded!= operator for node comparisons
    bool operator!= (const Node* rhs) const
    {
      return key != rhs->key;
    }  //operator!=


    //search function for a node to find a value (null check before calling)
    Node* const nodeSearch(int k)
    {
      if (k == key)
        return this;

      if (left != NULL && k < key)
        return left->nodeSearch(k);

      else if (right != NULL && k > key)
        return right->nodeSearch(k);

      else  //not found
        return NULL;
    }  //nodeSearch()


    void preorderWalk() const
    {
      cout << key << '\n';

      if (left != NULL)
        left->preorderWalk();

      if (right != NULL)
        right->preorderWalk();
    }  //preorderWalk()


    void postorderWalk() const
    {
      if (left != NULL)
        left->postorderWalk();

      if (right != NULL)
        right->postorderWalk();

      cout << key << '\n';
    }  //postorderWalk()


    void inorderWalk() const
    {
      if (left != NULL)
        left->inorderWalk();

      cout << key << '\n';

      if (right != NULL)
        right->inorderWalk();
    }  //inorderWalk()


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
    ~BST()
    {
      if (root)
      {
      root->cleanTree();  //free all allocated memory
      delete root;  // last node
      }
    }  //~BST()


    Node* const treeMinimum(Node* x) const
    {
      while (x->left != NULL)
        x = x->left;
      return x;
    }  //treeMinimum()


    //replaces one subtree as a child of its parent with another subtree
    void transplant(Node* u, Node* v)
    {
      //if root
      if (u->parent == NULL)
        root = v;

      else if (u == u->parent->left)
        u->parent->left = v;

      else
        u->parent->right = v;

      if (v != NULL)  //then update
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


    Node* const treeSearch(int k) const
    {
      if (root == NULL)
        return NULL;

      return root->nodeSearch(k);
    }  //treeSearch()


    void treeDelete(Node* z)
    {
      Node* y;

      if (z->left == NULL)
        transplant(z, z->right);

      else if (z->right == NULL)
        transplant(z, z->left);

      else  //else we need to find the successor
      {
        y = treeMinimum(z->right);

         //if y is not z's left child, replace y as a child of its parent by y’s
         //right child and turn z’s right child into y’s right child.
        if (y->parent != z)
        {
          transplant(y, y->right);
          y->right = z->right;
          y->right->parent = y;
        }  //replaced y as a child of its parent

        //replace z as a child of its parent by y and replace y's left child
        //by z's left child
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
      }

      //free allocated memory
      delete z;
    }  //treeDelete()


    void preorderTreeWalk() const
    {
      if (root != NULL)
        root->preorderWalk();
    }  //preorderTreeWalk()


    void postorderTreeWalk() const
    {
      if (root != NULL)
        root->postorderWalk();
    }  //postorderTreeWalk()


    void inorderTreeWalk() const
    {
      if (root != NULL)
        root->inorderWalk();
    }  //inorderTreeWalk()
};  //class BST


int main(int argc, char* argv[])
{
  char command = ' ';  //assign to appease valgrind
  int key;
  string walk;
  Node* z;
  BST* tree = new BST();
  bool incoming_input = true;

  //while there are still input commands
  while (incoming_input) {
    cin >> command;
    switch (command)
    {
      case 'i':
        cin >> key;
        z = new Node (NULL, NULL, NULL, key);
        tree->treeInsert(z);
        break;

      case 'd':
        cin >> key;
        z = tree->treeSearch(key);
        if (z != NULL) //if z is null, we did not find that node so do nothing
          tree->treeDelete(z);
        break;

      case 'o':
        cin >> walk;

        if (walk == "pre")
        {
          tree->preorderTreeWalk();
          break;
        }

        else if (walk == "post")
        {
          tree->postorderTreeWalk();
          break;
        }

        else  //else this is an inorder walk
        {
          tree->inorderTreeWalk();
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
