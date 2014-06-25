// C20Stack1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Demonstrates the STL stack
#include <iostream>
#include <fstream>
#include <stack>
#include <list>
#include <vector>
#include <string>
using namespace std;

// Default: deque<string>:
typedef stack<string> Stack1;
// Use a vector<string>:
typedef stack<string, vector<string> > Stack2;
// Use a list<string>:
typedef stack<string, list<string> > Stack3;

int main(int argc, char* argv[]) {

  ifstream in("ReadMe.txt");
  if(in == NULL)
	  return 0;
  Stack1 textlines; // Try the different versions
  // Read file and store lines in the stack:
  string line;
  while(getline(in, line)) 
    textlines.push(line + "\n");
  // Print lines from the stack and pop them:
  while(!textlines.empty()) {
    cout << textlines.top();
    textlines.pop();
  }
  cin.get();
} ///:~

