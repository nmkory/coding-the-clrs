#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
  char c;
  int length;
  ifstream inf(argv[1]);

  inf >> c;
  length = c - '0';


  return 0;
}  //main()
