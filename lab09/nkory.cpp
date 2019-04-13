// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
#include <iostream>
#include <queue>

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
};

bool operator<(const Node& lhs, const Node& rhs) {
  return lhs.freq < rhs.freq;
}

bool operator>(const Node& lhs, const Node& rhs) {
  return lhs.freq > rhs.freq;
}

bool operator==(const Node& lhs, const Node& rhs) {
  return lhs.freq == rhs.freq;
}

bool operator!=(const Node& lhs, const Node& rhs) {
  return lhs.freq != rhs.freq;
}


int main(int argc, char* argv[])
{
  priority_queue<Node, vector<Node>, greater<vector<Node>::value_type>> queue;

  Node n1;
  Node n2;
  Node n3;

  n1.freq = 1;
  n2.freq = 2;
  n3.freq = 3;

  if (n1 < n2)
    std::cout << "Works" << '\n';

  queue.push(n3);
  queue.push(n1);
  queue.push(n2);

  cout << queue.top().freq << '\n';


  return 0;
}  //main()
