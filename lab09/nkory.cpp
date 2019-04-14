// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Node {
  public:
    Node* left{NULL};
    Node* right{NULL};
    int freq{0};
    char c{'#'};
    Node() {}
    Node(Node* leftNode, Node* rightNode, int charFreq, char character)
      : left (leftNode), right (rightNode), freq (charFreq), c (character) {}
    Node& operator= (const Node &n) {
      left = n.left;
      right = n.right;
      freq = n.freq;
      c = n.c;
    }
};


struct NodeComparator {
   bool operator() (const Node* lhs, const Node* rhs) const {
     return lhs->freq > rhs->freq;
   }
};


void inorderTreeWalk(Node* node, string huffman_code) {
  if (node->left != NULL)
    inorderTreeWalk(node->left, huffman_code + "0");

  if (node->c != '#')
     std::cout << node->c << ":" << huffman_code <<'\n';

  if (node->right != NULL)
    inorderTreeWalk(node->right, huffman_code + "1");
}


void cleanTree(Node* node)
{
  if (node->left)
  {
    cleanTree(node->left);
    delete node->left;
  } // if node left

  if (node->right)
  {
    cleanTree(node->right);
    delete node->right;
  } // if node right
} //clean()


int main(int argc, char* argv[])
{
  priority_queue<Node*, vector<Node*>, NodeComparator> queue;
  char c;
  int c_freq;
  int i;
  int n = 6;
  Node* z;

  for (i = 1, c = 'A'; i <= n; i++, c++) {
    cin >> c_freq;
    z = new Node(NULL, NULL, c_freq, c);
    queue.push( z );
  }

  for (i = 1; i <= (n - 1); i++) {
    z = new Node();
    z->left = queue.top();
    queue.pop();
    z->right = queue.top();
    queue.pop();
    z->freq = z->left->freq + z->right->freq;
    queue.push( z );
  }

  z = queue.top();
  inorderTreeWalk(z, "");

  cleanTree(z);
  delete z;

  return 0;
}  //main()
