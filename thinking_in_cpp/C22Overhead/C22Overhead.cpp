// C22Overhead.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Virtual base class overhead
#include <fstream>
using namespace std;
ofstream out("overhead.txt");

class MBase {
public:
	virtual void f() const {};
	virtual ~MBase() {}
};

class NonVirtualInheritance
	: public MBase {};

class VirtualInheritance
	: virtual public MBase {};

class VirtualInheritance2
	: virtual public MBase {};

class MI
	: public VirtualInheritance,
	public VirtualInheritance2 {};

#define WRITE(ARG) \
	out << #ARG << " = " << ARG << endl;

int main() {
	MBase b;
	WRITE(sizeof(b));
	NonVirtualInheritance nonv_inheritance;
	WRITE(sizeof(nonv_inheritance));
	VirtualInheritance v_inheritance;
	WRITE(sizeof(v_inheritance));
	MI mi;
	WRITE(sizeof(mi));
} ///:~
