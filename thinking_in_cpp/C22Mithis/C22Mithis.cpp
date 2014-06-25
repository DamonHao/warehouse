// C22Mithis.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// MI and the "this" pointer
#include <fstream>
using namespace std;
ofstream out("mithis.txt");

class Base1 {
	char c[0x10];
public:
	void printthis1() {
		out << "Base1 this = " << this << endl;
	}
};

class Base2 {
	char c[0x10];
public:
	void printthis2() {
		out << "Base2 this = " << this << endl;
	}
};

class Member1 {
	char c[0x10];
public:
	void printthism1() {
		out << "Member1 this = " << this << endl;
	}
};

class Member2 {
	char c[0x10];
public:
	void printthism2() {
		out << "Member2 this = " << this << endl;
	}
};

class MI : public Base1, public Base2 {
	Member1 m1;
	Member2 m2;
public:
	void printthis() {
		out << "MI this = " << this << endl;
		printthis1();
		printthis2();
		m1.printthism1();
		m2.printthism2();
	}
};

int main() {
	MI mi;
	out << "sizeof(mi) = "
		<< hex << sizeof(mi) << " hex" << endl;
	mi.printthis();
	// A second demonstration:
	Base1* b1 = &mi; // Upcast
	Base2* b2 = &mi; // Upcast
	out << "Base 1 pointer = " << b1 << endl;
	out << "Base 2 pointer = " << b2 << endl;
} ///:~


