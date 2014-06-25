// C19TypenameID.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template<class T> class X {
  // Without typename, you should get an error:
  typename T::id i;
public:
  void f() { i.g(); }
};
class Y {
public:
  class id {
  public:
    void g() { cout<<"1"<<endl; }
  };
};

int _tmain(int argc, _TCHAR* argv[])
{
  Y y;
  X<Y> xy;
  xy.f();
  cin.get();
  return 0;
}

