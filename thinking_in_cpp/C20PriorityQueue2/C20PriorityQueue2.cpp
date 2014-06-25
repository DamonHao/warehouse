// C20PriorityQueue2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Changing the priority
#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Reverse {
  bool operator()(int x, int y) {
    return x > y;
  }
};

int main() {
  priority_queue<int, vector<int>, Reverse> pqi;
  // Could also say:
  // priority_queue<int, vector<int>, 
  //   greater<int> > pqi;
  srand(time(0));
  for(int i = 0; i < 100; i++)
    pqi.push(rand() % 25);
  while(!pqi.empty()) {
    cout << pqi.top() << ' ';
    pqi.pop();
  }
  cin.get();
} ///:~
