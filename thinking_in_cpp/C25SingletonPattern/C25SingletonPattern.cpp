// C25SingletonPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Singleton {
	static Singleton s;
	int i;
	Singleton(int x) : i(x) { }
	//the compiler will auto create the below function 
	//if you don't declare it explicitly
	void operator=(Singleton&);
	Singleton(const Singleton&);
public:
	static Singleton& getHandle() {
		return s;
	}
	int getValue() { return i; }
	void setValue(int x) { i = x; }
};

Singleton Singleton::s(47);

int main() {
	Singleton& s = Singleton::getHandle();
	cout << s.getValue() << endl;
	Singleton& s2 = Singleton::getHandle();
	s2.setValue(9);
	cout << s.getValue() << endl;
} ///:~
