// C24RTTIwithExceptions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <typeinfo>
#include <iostream>
using namespace std;
class X { public: virtual ~X(){} };
class B { public: virtual ~B(){} };
class D : public B {};

int main() {
  D d;
  B & b = d; // Upcast to reference
  try {
    X& xr = dynamic_cast<X&>(b);
  }
  catch(...) {
	// can use standard cpp exception type bad_cast here 
    cout << "dynamic_cast<X&>(b) failed" 
         << endl;
  }
  X* xp = 0;
  try {
    typeid(*xp); // Throws exception
  } catch(bad_typeid) {
    cout << "Bad typeid() expression" << endl;
  }
  cin.get();
} ///:~


