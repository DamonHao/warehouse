// C23Except.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Basic exceptions
// Exception specifications & unexpected()
#include <exception>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Up {};
class Fit {};
void g();

void f(int i) throw (Up, Fit) {
	switch(i) {
	case 1: throw Up();
	case 2: throw Fit();
	}
	g();
}

// void g() {} // Version 1
void g() { throw 47; } // Version 2
// (Can throw built-in types)

void my_unexpected() {
	cout << "unexpected exception thrown";
	//exit(1);
}

int main() {
	set_unexpected(my_unexpected);
	// (ignores return value)
	for(int i = 1; i <=3; i++)
		try {
			f(i);
	} catch(Up) {
		cout << "Up caught" << endl;
	} catch(Fit) {
		cout << "Fit caught" << endl;
	}
	cin.get();
} ///:~