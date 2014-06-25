// C23FunctionTryBlock.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Function-level try blocks
#include <iostream>
using namespace std;

int main() try {
	throw "main";
} catch(const char* msg) {
	cout << msg << endl;
	cin.get();
} ///:~

