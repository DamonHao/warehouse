// C24RTTIWithoutPolymorphism.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cassert>
#include <typeinfo>
#include <iostream>
using namespace std;

class X {
 int i; 
public:
  // ...
};

class Y : public X { 
  int j;
public:
  // ...
};

int main() {
  X* xp = new Y;
  // the two below condition is true;
  assert(typeid(*xp) == typeid(X));
  assert(typeid(*xp) != typeid(Y));
  cin.get();
} ///:~
