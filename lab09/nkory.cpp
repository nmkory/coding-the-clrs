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


    bool operator() (const Node* lhs, const Node* rhs) const {
      return lhs->freq > rhs->freq;
    }  //operator()


    void encode(string huffman_code, string* cipher) {
      if (left != NULL)
        left->encode(huffman_code + "0", cipher);

      if (c != '#')
         cipher[c - 65] = huffman_code;

      if (right != NULL)
        right->encode(huffman_code + "1", cipher);
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
};  //class Node


int main(int argc, char* argv[])
{
  char c;
  int c_freq;
  int i;
  int n = 6;
  Node* z;
  string* cipher = new string[n];
  priority_queue<Node*, vector<Node*>, Node> queue;

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
  z->encode("", cipher);

  for (i = 0, c = 'A'; i < n; i++, c++) {
    std::cout << c << ":" << cipher[i] << '\n';
  }

  z->cleanTree();
  delete z;
  delete [] cipher;

  return 0;
}  //main()
