// C23Nudep.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Naked pointers
#include <fstream>
#include <cstdlib>
using namespace std;
ofstream out("nudep.txt");

class Cat {
public:
	Cat() { out << "Cat()" << endl; }
	~Cat() { out << "~Cat()" << endl; }
};

class Dog {
public:
	void* operator new(size_t sz) {
		out << "allocating a Dog" << endl;
		throw int(47);
	}
	void operator delete(void* p) {
		out << "deallocating a Dog" << endl;
		::delete p;
	}
};

class UseResources {
	Cat* bp;
	Dog* op;
public:
	UseResources(int count = 1) {
		out << "UseResources()" << endl;
		bp = new Cat[count];
		op = new Dog;
	}
	~UseResources() {
		out << "~UseResources()" << endl;
		delete []bp; // Array delete
		delete op;
	}
};

int main() {
	try {
		UseResources ur(3);
	} catch(int) {
		out << "inside handler" << endl;
	}
} ///:~
