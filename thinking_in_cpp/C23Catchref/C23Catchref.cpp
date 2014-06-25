// C23Catchref.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Why catch by reference?
#include <iostream>
using namespace std;

class Base {
public:
	virtual void what() {
		cout << "Base" << endl;
	}
};

class Derived : public Base {
public:
	void what() {
		cout << "Derived" << endl;
	}
};

void f() { throw Derived(); }



int main() {
	try {
		f();
	} catch(Base b) {
		b.what();
	}
	try {
		f();
	} catch(Base& b) {
		b.what();
	}

	cin.get();
} ///:~

