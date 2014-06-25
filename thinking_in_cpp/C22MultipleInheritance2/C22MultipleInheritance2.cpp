// C22MultipleInheritance2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Virtual base classes
#include "purge.h"
#include <iostream>
#include <vector>
using namespace std;

class MBase {
public:
	virtual char* vf() const = 0;
	virtual ~MBase() {}
};

class D1 : virtual public MBase {
public:
	char* vf() const { return "D1"; }
};

class D2 : virtual public MBase {
public:
	char* vf() const { return "D2"; }
};

// MUST explicitly disambiguate vf():
class MI : public D1, public D2 {
public:
	char* vf() const { return D1::vf();}
};

int main() {
	vector<MBase*> b;
	b.push_back(new D1);
	b.push_back(new D2);
	b.push_back(new MI); // OK
	for(int i = 0; i < b.size(); i++)
		cout << b[i]->vf() << endl;
	purge(b);
	cin.get();
} ///:~