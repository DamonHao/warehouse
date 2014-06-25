// C12AutomaticOperatorEquals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Bar {
public:
	Bar& operator=(const Bar&) {
		cout << "inside Bar::operator=()" << endl;
		return *this;
	}
};

class MyType {
	Bar b;
};

int _tmain(int argc, _TCHAR* argv[])
{
	MyType a, b;
	//the complier will automatically create a 
	//type:operator=(type) if you don't make one
	//but in general,you don't want to let the complier
	//do this for you!!!
	a = b; // Prints: "inside Bar::operator=()"
	cin.get();
	return 0;
}

