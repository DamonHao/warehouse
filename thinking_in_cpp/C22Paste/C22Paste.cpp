// C22Paste.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Fixing a mess with MI
#include "Vendor.h"
#include <fstream>
using namespace std;

ofstream out("paste.txt");

class MyBase { // Repair Vendor interface
public:
	virtual void v() const = 0;
	virtual void f() const = 0;
	// New interface function:
	virtual void g() const = 0;
	virtual ~MyBase() { out << "~MyBase()\n"; }
};

class Paste1 : public MyBase, public Vendor1 {
public:
	void v() const {
		out << "Paste1::v()\n";
		Vendor1::v();
	}
	void f() const {
		out << "Paste1::f()\n";
		Vendor1::f();
	}
	void g() const {
		out << "Paste1::g()\n";
	}
	~Paste1() { out << "~Paste1()\n"; }
};

int main() {
	Paste1& p1p = *new Paste1;
	MyBase& mp = p1p; // Upcast
	out << "calling f()\n";
	mp.f();  // Right behavior
	out << "calling g()\n";
	mp.g(); // New behavior
	out << "calling A(p1p)\n";
	A(p1p); // Same old behavior
	out << "calling B(p1p)\n";
	B(p1p);  // Same old behavior
	out << "delete mp\n";
	// Deleting a reference to a heap object:
	delete &mp; // Right behavior
} ///:~