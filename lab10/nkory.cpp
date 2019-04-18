// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
// I did not work with anyone on this assignment.
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Node {
  public:
    Node* left {NULL};
    Node* right {NULL};
    int freq {0};
    char c {'#'};

    Node() {}
    Node(Node* leftNode, Node* rightNode, int charFreq, char character)
      : left (leftNode), right (rightNode), freq (charFreq), c (character) {}
    ~Node() {}

    //overloaded () operator to organize min priority_queue
    bool operator() (const Node* lhs, const Node* rhs) const
    {
      return lhs->freq > rhs->freq;
    }  //operator()

    //used to encode the huffman strings after running algo
    void encode(string huffman_code, string* cipher)
    {
      if (left != NULL)
        left->encode(huffman_code + "0", cipher);

      //ascii offset by 65 assumes we start with "A"
      if (c != '#')
         cipher[c - 65] = huffman_code;

      if (right != NULL)
        right->encode(huffman_code + "1", cipher);
    }  //encode()


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


int main(int argc, char* argv[])
{
  char c;
  int c_freq;
  int i;
  int n = 6;
  Node* z;
  string* cipher = new string[n];
  priority_queue<Node*, vector<Node*>, Node> queue;

  //read in char freq from stdin and push onto priority_queue
  for (i = 1, c = 'A'; i <= n; i++, c++)
  {
    cin >> c_freq;
    z = new Node(NULL, NULL, c_freq, c);
    queue.push(z);
  }  //char nodes are organized in the priority_queue

  //huffman algorithm
  for (i = 1; i <= (n - 1); i++)
  {
    z = new Node();

    z->left = queue.top();
    queue.pop();

    z->right = queue.top();
    queue.pop();

    z->freq = z->left->freq + z->right->freq;
    queue.push(z);
  }  //z is ready to be encoded

  //pop last node from queue and load huffman codes into cipher
  z = queue.top();
  queue.pop();
  z->encode("", cipher);

  //stdout the huffman codes
  for (i = 0, c = 'A'; i < n; i++, c++)
    cout << c << ":" << cipher[i] << '\n';

  //free allocated memory
  z->cleanTree();
  delete z;
  delete [] cipher;

  return 0;
}  //main()
