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
    ~Node() {}


    Node& operator= (const Node &n) {
      left = n.left;
      right = n.right;
      freq = n.freq;
      c = n.c;
    }  //operator=


    bool operator() (const Node* lhs, const Node* rhs) const {
      return lhs->freq > rhs->freq;
    }  //operator()


    void encode(string huffman_code) {
      if (left != NULL)
        left->encode(huffman_code + "0");

      if (c != '#')
         std::cout << c << ":" << huffman_code <<'\n';

      if (right != NULL)
        right->encode(huffman_code + "1");
    }  //encode()


    void cleanTree()
    {
      if (left)
      {
        left->cleanTree();
        delete left;
      } // if node left

      if (right)
      {
        right->cleanTree();
        delete right;
      } // if node right
    } //cleanTree()
};


int main(int argc, char* argv[])
{
  priority_queue<Node*, vector<Node*>, Node> queue;
  char c;
  int c_freq;
  int i;
  int n = 6;
  Node* z;

  for (i = 1, c = 'A'; i <= n; i++, c++) {
    cin >> c_freq;
    z = new Node(NULL, NULL, c_freq, c);
    queue.push(z);
  }

  for (i = 1; i <= (n - 1); i++) {
    z = new Node();
    z->left = queue.top();
    queue.pop();
    z->right = queue.top();
    queue.pop();
    z->freq = z->left->freq + z->right->freq;
    queue.push(z);
  }

  z = queue.top();
  queue.pop();
  z->encode("");

  z->cleanTree();
  delete z;

  return 0;
}  //main()
