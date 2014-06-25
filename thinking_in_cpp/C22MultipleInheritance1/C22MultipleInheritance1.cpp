// C22MultipleInheritance1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// MI & ambiguity
#include "purge.h"
#include <iostream>
#include <vector>
using namespace std;

class MBase {
public:
	virtual char* vf() const = 0;
	virtual ~MBase() {}
};

class D1 : public MBase {
public:
	char* vf() const { return "D1"; }
};

class D2 : public MBase {
public:
	char* vf() const { return "D2"; }
};

// Causes error: ambiguous override of vf():
//class MI : public D1, public D2 {};

int main() {
	vector<MBase*> b;
	b.push_back(new D1);
	b.push_back(new D2);
	// Cannot upcast: which subobject?:
	//b.push_back(new MI);
	for(int i = 0; i < b.size(); i++)
		cout << b[i]->vf() << endl;
	purge(b);
	cin.get();
} ///:~

